#ifndef USERINTERFACEPROXY_HPP
#define USERINTERFACEPROXY_HPP

#include <render/userInterface.hpp>

class UserInterfaceProxy : public UserInterface
{
	std::vector< UserInterface > userInterfaces;
public:
	void render();
	void choice();

	UserInterfaceProxy();
}
