#pragma once
#include <ostream>
#include <exception>
using namespace std;
class MyException :public std::exception
{
public:
	MyException(const std::string& excp,bool door);

	virtual const char* what() const noexcept;
	bool getDoor()
	{
		return m_door;
	}
private:
	std::string m_excp;
	bool m_door=false;
};