rcstring: rcstring.o
	g++ -g -Wall -pedantic $^ -o $@

rcstring.o: rcstring.cpp rcstring.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm rcstring.o rcstring