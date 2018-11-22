teststring: teststring.o
	g++ -g -Wall -pedantic $^ -o $@

teststring.o: teststring.cpp mystring.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm teststring.o teststring