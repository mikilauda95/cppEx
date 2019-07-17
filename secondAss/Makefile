CC=g++
CFLAGS="-I. -std=c++11"

OBJ1 = testgraph.o Graph.o 
OBJ2 = testqueue.o PriorityQueue.o
OBJ3 = testalgo.o Graph.o PriorityQueue.o Algo.o
OBJ4 = testfile.o Graph.o 
OBJ5 = testprim.o Graph.o PriorityQueue.o prim.o 
OBJ = main.o Graph.o PriorityQueue.o Algo.o

DEPS = Graph.h PriorityQueue.h Algo.h Mypair.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


testgraph: $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS)

testqueue: $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS)

testalgo: $(OBJ3)
	$(CC) -o $@ $^ $(CFLAGS)

testfile: $(OBJ4)
	$(CC) -o $@ $^ $(CFLAGS)

testprim: $(OBJ5)
	$(CC) -o $@ $^ $(CFLAGS)

mc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o
