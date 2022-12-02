DIR = $(notdir $(CURDIR))
CXXFLAGS = -Wall -Wextra
LDFLAGS = -Wall -Wextra
LDLIBS = -lm

.PHONY: clean all
all: Generator.x Stack.x ONP.x

Generator.x: Generator.o
Generator.o: Generator.cpp

Stack.x: Stack.o
Stack.o: Stack.cpp ArrayStack.hpp LinkedStack.hpp

ONP.x: ONP.o
ONP.o: ONP.cpp ArrayStack.hpp LinkedStack.hpp

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )