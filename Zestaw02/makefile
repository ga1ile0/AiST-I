DIR = $(notdir $(CURDIR))
CXXFLAGS = -Wall -Wextra
LDFLAGS = -Wall -Wextra
LDLIBS = -lm

.PHONY: clean all
all: Generator.x Queue.x Radix.x

Generator.x: Generator.o
Generator.o: Generator.cpp

Queue.x: Queue.o
Queue.o: Queue.cpp ArrayQueue.hpp LinkedQueue.hpp

Radix.x: Radix.o
Radix.o: Radix.cpp ArrayQueue.hpp LinkedQueue.hpp

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )