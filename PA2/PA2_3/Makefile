all: run-tdll

run-tdll: MinQueue-main.o 
	c++ -std=c++11 MinQueue-main.o -o run-tmq

MinQueue-main.o: MinQueue-main.cpp TemplatedDLList.h MinQueue.h
	c++ -std=c++11 -c MinQueue-main.cpp

clean:
	rm *.o run-tmq
