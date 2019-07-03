CC=g++
CFLAGS=-I.

OBJ = testalgo.o Graph.o PriorityQueue.o Algo.o
OBJ1 = testgraph.o Graph.o 
OBJ2 = testqueue.o PriorityQueue.o

DEPS = Graph.h PriorityQueue.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


testgraph: $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS)

testqueue: $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS)

testalgo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

