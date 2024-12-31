#ifndef _LIST_H
#define _LIST_H

#include "object.hpp"

#define INIT_SIZE 8
#define INC       2

#ifdef __cplusplus
extern "C"
{
#endif

	namespace ykes
	{
		struct List
		{
		    private:
			void realloc_obj(size_t new_size);

		    public:
			List();
			~List();

			Object *list;

			size_t count;
			size_t len;

			void insert(size_t index, Object *obj);
			void remove(size_t index);
			void remove(Object *obj);
			void push(Object *obj);
			void operator+=(List &);
			void operator=(List const &);

			void clear(void);
			void dump(void);
		};
	} // namespace ykes

#ifdef __cplusplus
}
#endif

#endif
