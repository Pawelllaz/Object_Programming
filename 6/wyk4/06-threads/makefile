all: threads1 threads2 volatile1 volatile2 threads1_cxx11 threads2_cxx11 volatile1_cxx11 volatile1_cxx11.s volatile2_cxx11 volatile2_cxx11.s

threads1: threads1.o
	g++ -g $^ -lpthread -o$@

threads1.o: threads1.cpp
	g++ -g -c -Wall -pedantic $< -o $@

threads2: threads2.o
	g++ -g $^ -o $@ -lpthread

threads2.o: threads2.cpp rcstring.h
	g++ -g -c -Wall -pedantic $< -o $@

threads1_cxx11: threads1_cxx11.cpp
	g++ -g -std=c++11 -pthread -Wall -pedantic $< -o $@

threads2_cxx11: threads2_cxx11.cpp
	g++ -g -std=c++11 -pthread -Wall -pedantic $< -o $@

volatile1_cxx11: volatile1_cxx11.cpp
	g++ -g -std=c++11 -pthread -Wall -pedantic -O2 $< -o $@	

volatile1_cxx11.s: volatile1_cxx11.cpp
	g++ -g -std=c++11 -pthread -Wall -pedantic -S -O2 $< -o $@	
	
volatile2_cxx11: volatile2_cxx11.cpp
	g++ -g -std=c++11 -pthread -Wall -pedantic -O2 $< -o $@	

volatile2_cxx11.s: volatile2_cxx11.cpp
	g++ -g -std=c++11 -pthread -Wall -pedantic -S -O2 $< -o $@	
	
volatile1: volatile1.o
	g++ -g $^ -o $@ -lpthread

volatile1.o: volatile1.s
	g++ -g -c $< -o $@

volatile1.s: volatile1.cpp
	g++ -O2 -S -g -c -Wall -pedantic $< -o $@


volatile2: volatile2.o
	g++ -g $^ -o $@ -lpthread

volatile2.o: volatile2.s
	g++ -g -c $< -o $@

volatile2.s: volatile2.cpp
	g++ -O2 -S -g -c -Wall -pedantic $< -o $@


.PHONY: clean

clean:
	-rm threads1.o threads1 threads2.o threads2 volatile1.o volatile1 volatile2.o volatile2 volatile1.s volatile2.s threads1_cxx11 threads2_cxx11 volatile1_cxx11 volatile1_cxx11.s volatile2_cxx11 volatile2_cxx11.s
