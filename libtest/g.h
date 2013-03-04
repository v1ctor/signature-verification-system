class G
{
public:
	G();
	~G();
	void doAction();

};


//C API
extern "C"
{
	G* G_new();
	void G_doAction(G* g);
	void G_delete(G* g);
}
