PYINC = /usr/include/python2.7/
PYLIB = /usr/lib/python2.7/
SWIG = /usr/bin/swig
LIB_SOURCES = Signature.cpp MongoDbDataSource.cpp Configuration.cpp 
LIB_HEADERS = Signature.h MongoDbDataSource.h DataSource.h Configuration.h

LIBS += `pkg-config --libs libconfig++` -L${PYLIB} -lpython2.7 -lmongoclient
CXXFLAGS += `pkg-config --cflags libconfig++`

OBJS = $(notdir $(patsubst %.cpp,%.o,$(wildcard *.cpp))) 

all: _sal.so sal.py test

_sal.so: ${OBJS} sal_wrap.o 
	g++ -shared sal_wrap.o ${OBJS} ${LIBS} -o $@

sal_wrap.o: sal_wrap.cxx ${LIB_HEADERS}
	g++ sal_wrap.cxx -c -g -I${PYINC} -fPIC

sal_wrap.cxx: sal.i
	${SWIG} -c++ -python sal.i

sal.py: sal.i
	${SWIG} -c++ -python sal.i

%.o:%.cpp
	${CXX} $< -c -g -Wno-deprecated -fPIC ${CXXFLAGS} ${LIBS}
	
clean:
	rm -rf *.so *.o *.cxx *.pyc *.py

rebuild: clean all

list:
	@echo ${OBJS}

test:
	@echo "------------Start testing-------------"
	python libtest.py