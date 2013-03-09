#include "g.h"
#include <iostream>

G::G()
{
	std::cout << "constructor" << std::endl;
}

G::~G()
{
	std::cout << "destructor" << std::endl;
}

void G::doAction()
{
	std::cout << "action" << std::endl;
}

