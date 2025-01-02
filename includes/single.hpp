
#pragma once

namespace ykes
{

	class Singleton
	{
	    private:
		Singleton();
		Singleton(Singleton const &copy);
		void operator=(Singleton const &copy);

	    public:
		~Singleton();
		static inline Singleton &get_instance()
		{
			static Singleton s;
			return s;
		}
	};
} // namespace ykes
