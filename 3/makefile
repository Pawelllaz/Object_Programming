testvector: testvector.o
	g++ -g -Wall $^ -o $@

testvector.o: testvector.cpp vector.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm testvector.o testvector