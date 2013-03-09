PYINC = /usr/include/python2.7/
PYLIB = /usr/lib/python2.7/
SWIG = /usr/bin/swig

all: _g.so g.py

_g.so: g_wrap.o g.o
	g++ -shared g_wrap.o g.o -L${PYLIB} -lpython2.7 -o $@

g_wrap.o: g_wrap.cxx g.h
	g++ g_wrap.cxx -c -g -I${PYINC} -fPIC

g_wrap.cxx: g.i
	${SWIG} -c++ -python g.i

g.py: g.i
	${SWIG} -c++ -python g.i

g.o: g.cpp g.h
	g++ g.cpp -c -g -Wno-deprecated -fPIC


