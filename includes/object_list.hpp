#pragma once

#include "object.hpp"

#define INIT_SIZE 8
#define INC       2

namespace ykes
{
	struct List
	{
	    private:
		void realloc_obj(size_t new_size);

	    public:
		List();
		~List();

		Object **list;

		size_t count;
		size_t len;

		void insert(size_t index, Object *obj);
		int  remove(size_t index);
		int  remove(Object *obj);
		void push(Object *obj);

		List operator+(List &);
		void operator+=(List &);
		void operator=(List const &);

		void clear(void);
		void dump(void) const;
	};
} // namespace ykes
