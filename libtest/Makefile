
all:
	g++ -fPIC -c g.cpp 
	g++ -shared -Wl,-soname,libg.so.1 -o libg.so.1.0.1 g.o 
	ln -sf libg.so.1.0.1 libg.so.1
	ln -sf libg.so.1.0.1 libg.so
	g++ main.cpp -lg -L.


run:
	LD_LIBRARY_PATH=. ./a.out

python:
	python gWrapper.py
