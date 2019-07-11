CC=g++
CFLAGS="-I. -std=c++11"

OBJ1 = testgraph.o Graph.o 
OBJ2 = testqueue.o PriorityQueue.o
OBJ3 = testalgo.o Graph.o PriorityQueue.o Algo.o
OBJ = main.o Graph.o PriorityQueue.o Algo.o

DEPS = Graph.h PriorityQueue.h Algo.h Mypair.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


testgraph: $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS)

testqueue: $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS)

testalgo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

mc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
