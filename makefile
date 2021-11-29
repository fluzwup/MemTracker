CC= gcc 
CXX= g++ -std=c++11 -fpermissive
AR= ar
CFLAGS= -ggdb 
CXXFLAGS= -ggdb

OBJECTS= MemTracker.o tracker.o trackerpp.o

all:	libMemTracker.a test_c test_cpp
	@ echo
	@ echo "Running tests."
	./test_c
	./test_cpp
	@ echo

clean:
	- rm -f $(OBJECTS) *.o *.a test_c test_cpp

libMemTracker.a: $(OBJECTS)
	- rm -f libMemTracker.a
	$(AR) crv libMemTracker.a $(OBJECTS)

test_c: libMemTracker.a test_c.o
	- rm -f test_c
	$(CXX) $(CFLAGS) test_c.o -L ./ -lMemTracker -o test_c 

test_cpp: libMemTracker.a test_cpp.o
	- rm -f test_cpp
	$(CXX) $(CFLAGS) test_cpp.o -L ./ -lMemTracker -o test_cpp 

$(OBJECTS) test_c.o test_cpp.o: MemTracker.h

