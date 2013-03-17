PYINC = /usr/include/python2.7/
PYLIB = /usr/lib/python2.7/
SWIG = /usr/bin/swig

all: _dtw.so dtw.py

_dtw.so: dtw_wrap.o dtw.o
	g++ -shared dtw_wrap.o dtw.o -L${PYLIB} -lpython2.7 -o $@

dtw_wrap.o: dtw_wrap.cxx dtw.h
	g++ dtw_wrap.cxx -c -g -I${PYINC} -fPIC

dtw_wrap.cxx: dtw.i
	${SWIG} -c++ -python dtw.i

dtw.py: dtw.i
	${SWIG} -c++ -python dtw.i

dtw.o: dtw.cpp dtw.h
	g++ dtw.cpp -c -g -Wno-deprecated -fPIC

clean:
	rm -rf *.so *.o *.cxx *.pyc *.py

rebuild: clean all
