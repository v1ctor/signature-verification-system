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


extern "C" {
	G* G_new(){return new G();}
	void G_doAction(G* g){g->doAction();}
	void G_delete(G* g){ delete g;}
}
