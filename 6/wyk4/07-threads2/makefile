all: threads1 threads2 threads3 threads3 threads4 threads5

threads1: threads1.o
	g++ -g $^ -o $@ -lpthread

threads1.o: threads1.cpp rcstring1.h
	g++ -g -c -Wall -pedantic $< -o $@

threads2: threads2.o
	g++ -g $^ -o $@ -lpthread

threads2.o: threads2.cpp rcstring2.h
	g++ -g -c -Wall -pedantic $< -o $@

threads3: threads3.o
	g++ -g $^ -o $@ -lpthread

threads3.o: threads3.cpp rcstring3.h
	g++ -g -c -Wall -pedantic $< -o $@

threads4: threads4.o
	g++ -g $^ -o $@ -lpthread

threads4.o: threads4.cpp
	g++ -g -c -Wall -pedantic $< -o $@

threads5: threads5.o
	g++ -g $^ -o $@ -lpthread

threads5.o: threads5.cpp mystring.h
	g++ -g -c -Wall -pedantic $< -o $@


.PHONY: clean

clean:
	-rm threads1.o threads1 threads2.o threads2 threads3.o threads3 threads4.o threads4 threads5.o threads5
