DIR = $(notdir $(CURDIR))
CXXFLAGS = -Wall -Wextra
LDFLAGS = -Wall -Wextra
LDLIBS = -lm

.PHONY: clean all
all: BinaryTree.x

BinaryTree.x: BinaryTree.o
BinaryTree.o: BinaryTree.cpp

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )