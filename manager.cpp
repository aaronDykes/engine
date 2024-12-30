
#include "manager.hpp"
void ykes::Manager::set_type(std::string m_type)
{
	this->m_type = m_type;
}

ykes::Manager::Manager()
{
}
ykes::Manager::~Manager()
{
}
std::string ykes::Manager::get_type(void)
{
	return this->m_type;
}

int ykes::Manager::start()
{
}
void ykes::Manager::end()
{
}