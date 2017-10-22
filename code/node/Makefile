CC=g++ "-std=c++17"
DEPS=node.h node_test.cc
node:
	$(CC) node.cc -c

node-test: node.o
	$(CC) node_test.cc node.o -o "node_test"

node-test-run: node-test
	./node_test

zap:
	rm -fv *.o node_test
