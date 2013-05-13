PYINC = /usr/include/python2.7/
PYLIB = /usr/lib/python2.7/
SWIG = /usr/bin/swig
LIB_SOURCES = AuthorizationManager.cpp Dtwsolver.cpp MongoDbDataSource.cpp Configuration.cpp 
LIB_HEADERS = AuthorizationManager.h DtwSolver.h MongoDbDataSource.h DataSource.h Configuration.h


LIBS += `pkg-config --libs libconfig++` -L${PYLIB} -lpython2.7 -lmongoclient -lboost_thread -lboost_system -lboost_filesystem -lssl -L/usr/lib 
CXXFLAGS += `pkg-config --cflags libconfig++` -g -ggdb

OBJS = $(notdir $(patsubst %.cpp,%.o,$(wildcard *.cpp))) 

CXX = g++

all: swig deploy test

swig: _libsal.so libsal.py
	
_libsal.so: ${OBJS} libsal_wrap.o 
	${CXX} -shared libsal_wrap.o ${OBJS}  ${LIBS} -Wl,-soname,libsal.so -o $@
	
libsal_wrap.o: libsal_wrap.cxx #${LIB_HEADERS}
	${CXX} libsal_wrap.cxx -c -I${PYINC} -fPIC

libsal_wrap.cxx: libsal.i
	${SWIG} -c++ -python -w315 libsal.i

libsal.py: libsal.i
	${SWIG} -c++ -python -w315 libsal.i

AuthorizationManager.o:AuthorizationManager.cpp
	${CXX} $< -c -Wno-deprecated -fPIC

DtwSolver.o:DtwSolver.cpp
	${CXX} $< -c -Wno-deprecated -fPIC

MongoDbDataSource.o:MongoDbDataSource.cpp
	${CXX} $< -c -Wno-deprecated -fPIC -lmongoclient -lboost_thread -lboost_system -lboost_filesystem

Configuration.o:Configuration.cpp
	${CXX} $< -c -Wno-deprecated -fPIC `pkg-config --cflags --libs libconfig++`

clean:
	rm -rf *.so *.o *.cxx *.pyc libsal.py build/

rebuild: clean all

deploy:
	rm -rf build/
	mkdir build/
	cp _libsal.so libsal.py data/* build/

test:
	cd build/ && python test.py && cd ..

list:
	@echo ${OBJS}
