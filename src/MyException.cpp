#include "MyException.h"

MyException::MyException(const std::string& excp,bool door) : m_excp(excp),m_door(door)
{
}

const char* MyException::what() const noexcept
{
	return m_excp.c_str();

}
