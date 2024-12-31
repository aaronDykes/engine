#include "object_list.hpp"
#include <iostream>
#include <string.h>

ykes::List::List()
{
	this->list  = NULL;
	this->list  = (Object *)malloc(sizeof(Object) * INIT_SIZE);
	this->count = 0;
	this->len   = INIT_SIZE;
}
ykes::List::~List()
{
	free(this->list);
	this->list = NULL;
}

void ykes::List::realloc_obj(size_t new_size)
{
	Object *p   = NULL;
	Object *src = NULL;

	src = (Object *)realloc(list, sizeof(Object) * new_size);

	list = src;

	src       = NULL;
	this->len = new_size;
	p         = NULL;
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

	*(this->list + index) = *obj;
}
void ykes::List::remove(size_t index)
{
	*(this->list + index) = *(this->list + --this->count);
}
void ykes::List::remove(Object *obj)
{
	for (size_t i = 0; i < this->count; i++)
		if (*(this->list + i) == *obj)
		{
			*(this->list + i) = *(this->list + --this->count);
			return;
		}
}
void ykes::List::push(Object *obj)
{
	if (this->count + 1 > this->len)
		realloc_obj(this->len * INC);

	*(this->list + this->count++) = *obj;
}
void ykes::List::clear(void)
{
	this->count = 0;
}

void ykes::List::operator+=(List &_list)
{
	for (size_t i = 0; i < _list.count; i++)
		this->push(_list.list + i);
}
void ykes::List::operator=(List const &list)
{
	this->list  = list.list;
	this->count = list.count;
	this->len   = list.len;
}

void ykes::List::dump(void)
{
	for (size_t i = 0; i < this->count; i++)
		std::cout << (this->list + i)->getType() << std::endl;
}