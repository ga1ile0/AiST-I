DIR = $(notdir $(CURDIR))
CXXFLAGS = -Wall -Wextra
LDFLAGS = -Wall -Wextra
LDLIBS = -lm

.PHONY: clean all
all: SelectionSort.x InsertionSort.x BubbleSort.x Generator.x

Generator.x: Generator.o
Generator.o: Generator.cpp

BubbleSort.x: BubbleSort.o
BubbleSort.o: BubbleSort.cpp

SelectionSort.x: SelectionSort.o
SelectionSort.o: SelectionSort.cpp

InsertionSort.x: InsertionSort.o
InsertionSort.o: InsertionSort.cpp

CountingSort.x: CountingSort.o
CountingSort.o: CountingSort.cpp

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )