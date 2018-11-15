teststack: teststack.o stack.o
	g++ -g -Wall $^ -o $@

stack.o: stack.cpp stack.h
	g++ -g -c -Wall $< -o $@

teststack.o: teststack.cpp stack.h
	g++ -g -c -Wall $< -o $@

.PHONY: clean

clean:
	-rm stack.o teststack.o teststack