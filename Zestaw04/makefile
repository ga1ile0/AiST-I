DIR = $(notdir $(CURDIR))
CXXFLAGS = -Wall -Wextra
LDFLAGS = -Wall -Wextra
LDLIBS = -lm

.PHONY: clean all
all: Generator.x ArrayList.x CursorList.x

Generator.x: Generator.o
Generator.o: Generator.cpp

CursorList.x: CursorList.o
CursorList.o: CursorList.cpp CursorList.hpp

ArrayList.x: ArrayList.o
ArrayList.o: ArrayList.cpp ArrayList.hpp

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )