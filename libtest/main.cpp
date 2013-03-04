#include "g.h"


int main()
{

	{
		G* g = new G() ;
		g->doAction();
		delete g;
	}

	{
		G* g = G_new();
		G_doAction(g);
		G_delete(g);
	}



	return 0;
}
