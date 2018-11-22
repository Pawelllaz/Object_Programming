all: exception1 exception2 exception3

exception1: exception1.o
	g++ -g -Wall -pedantic $^ -o $@

exception1.o: exception1.cpp
	g++ -g -c -Wall -pedantic $< -o $@

exception2: exception2.o
	g++ -g -Wall -pedantic $^ -o $@

exception2.o: exception2.cpp
	g++ -g -c -Wall -pedantic $< -o $@

exception3: exception3.o
	g++ -g -Wall -pedantic $^ -o $@

exception3.o: exception3.cpp
	g++ -g -c -Wall -pedantic $< -o $@


.PHONY: clean

clean:
	-rm exception1.o exception1 exception2.o exception2 exception3.o exception3