
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

void ykes::Manager::operator=(Manager const &m)
{
}
std::string ykes::Manager::get_type(void) const
{
	return this->m_type;
}

int ykes::Manager::start()
{
	return 0;
}
void ykes::Manager::end()
{
}
