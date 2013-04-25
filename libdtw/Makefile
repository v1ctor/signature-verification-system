PYINC = /usr/include/python2.7/
PYLIB = /usr/lib/python2.7/
SWIG = /usr/bin/swig
LIB_SOURCES = Signature.cpp MongoDbDataSource.cpp Configuration.cpp 
LIB_HEADERS = Signature.h MongoDbDataSource.h DataSource.h Configuration.h

LIBS += `pkg-config --libs libconfig++` -L${PYLIB} -lpython2.7 -lmongoclient -L/usr/lib #-lboost_thread-mt -lboost_filesystem -lboost_program_options -lboost_system
CXXFLAGS += `pkg-config --cflags libconfig++` -g -ggdb

OBJS = $(notdir $(patsubst %.cpp,%.o,$(wildcard *.cpp))) 

all: _libsal.so libsal.py build.test cxx.test py.test

_libsal.so: ${OBJS} libsal_wrap.o 
	g++ -shared libsal_wrap.o ${OBJS} ${LIBS} -Wl,-soname,libsal.so -o $@
	cp $@ test/libsal.so
		
libsal_wrap.o: libsal_wrap.cxx ${LIB_HEADERS}
	g++ libsal_wrap.cxx -c -g -I${PYINC} -fPIC

libsal_wrap.cxx: libsal.i
	${SWIG} -c++ -python -w315 libsal.i

libsal.py: libsal.i
	${SWIG} -c++ -python -w315 libsal.i

%.o:%.cpp
	${CXX} $< -c -g -Wno-deprecated -fPIC ${CXXFLAGS} ${LIBS}
	
clean:
	rm -rf *.so *.o *.cxx *.pyc libsal.py

rebuild: clean all

list:
	@echo ${OBJS}

build.test:
	g++ test/capitest.cpp -o test/capitest -lsal -Ltest/ -g -ggdb

py.test:
	@echo "------------Start python testing-------------"
	python libtest.py

cxx.test:
	@echo "------------Start cxx testing-------------"
	test/capitest mongo.cfg
		