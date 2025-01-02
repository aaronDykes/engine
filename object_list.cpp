#include "object_list.hpp"
#include <iostream>
#include <string.h>

ykes::List::List()
{
	this->list  = NULL;
	this->list  = (Object **)malloc(sizeof(Object *) * INIT_SIZE);
	this->count = 0;
	this->len   = INIT_SIZE;
}
ykes::List::~List()
{
	for (size_t i = 0; i < count; i++)
		delete *(list + i);
	free(this->list);
	this->list = NULL;
}

void ykes::List::realloc_obj(size_t new_size)
{
	Object  *p   = NULL;
	Object **src = NULL;

	src = (Object **)calloc(new_size, sizeof(Object *));
	src = (Object **)memmove(
	    (void *)src, (void *)list, sizeof(Object *) * count
	);

	free(list);
	list = NULL;
	list = src;

	len = new_size;
	src = NULL;
	p   = NULL;
}

void ykes::List::insert(size_t index, Object *obj)
{
	if (index >= this->len)
		realloc_obj(index * INC);

	else if (this->count + 1 > this->len)
		realloc_obj(this->len * INC);

	this->count++;

	for (size_t i = this->count - 1; i > index; i--)
		*(this->list + i) = *(this->list + i - 1);

	*(this->list + index) = obj;
}
int ykes::List::remove(size_t index)
{
	if (index > count)
		return -1;
	int i = --this->count;

	delete *(this->list + index);
	*(this->list + index) = NULL;
	*(this->list + index) = *(this->list + i);
	*(this->list + i)     = NULL;
	return 0;
}
int ykes::List::remove(Object *obj)
{
	for (size_t i = 0; i < this->count; i++)
		if (*(this->list + i) == obj)
		{
			int last = --this->count;
			delete *(this->list + i);

			*(this->list + i)    = NULL;
			*(this->list + i)    = *(this->list + last);
			*(this->list + last) = NULL;
			return 0;
		}

	return -1;
}

void ykes::List::push(Object *obj)
{
	if (count + 1 > len)
		realloc_obj(len * INC);

	*(list + count++) = obj;
}
void ykes::List::clear(void)
{
	for (size_t i = 0; i < count; i++)
		if (*(list + i) != NULL)
		{
			delete *(list + i);
			*(list + i) = NULL;
		}

	this->count = 0;
}

void ykes::List::operator+=(List &_list)
{
	for (size_t i = 0; i < _list.count; i++)
		this->push(*(_list.list + i));
}
ykes::List ykes::List::operator+(List &_list)
{
	List alloced = List();

	for (size_t i = 0; i < this->count; i++)
		alloced.push(*(this->list + i));

	for (size_t i = 0; i < _list.count; i++)
		alloced.push(*(_list.list + i));

	return alloced;
}
void ykes::List::operator=(List const &list)
{

	this->clear();
	free(this->list);
	this->list  = NULL;
	this->list  = list.list;
	this->count = list.count;
	this->len   = list.len;
}

void ykes::List::dump(void)
{
	for (size_t i = 0; i < this->count; i++)
		std::cout << (*(this->list + i))->getType() << std::endl;
}