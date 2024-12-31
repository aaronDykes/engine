#ifndef _OBJECT_H
#define _OBJECT_H

#include "vector.hpp"
#include <string>
/* #ifndef __cplusplus
extern "C"
{
#endif

#ifndef __cplusplus
}
#endif
 */
namespace ykes
{

	class Object
	{
	    private:
		int         id;
		std::string type;
		Vector      position;

	    public:
		Object();
		virtual ~Object();

		int         getId(void) const;
		std::string getType(void) const;
		Vector      getPosition(void) const;

		void setId(int o_id);
		void setType(std::string type);
		void setPosition(Vector o_position);
	};
} // namespace ykes

#endif
