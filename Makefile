CC = gcc
FLAGS = -Wall -std=c11 -ggdb

main: main.o tree.o list.o ware.o shelf.o utilise.o
	$(CC) $(FLAGS) -o $@ $^ 
tree: tree.o list.o ware.o shelf.o utilise.o 
	$(CC) $(FLAGS) -o $@ $^
utilise: utils.o
	$(CC) $(FLAGS) -o $@ -c $^
shelf: shelf.o utilise.o
	$(CC) $(FLAGS) -o $@ -c $^
list: list.o shelf.o
	$(CC) $(FLAGS) -o $@ -c $^
ware: ware.o utilise.o
	$(CC) $(FLAGS) -o $@ -c $^

clean:
	rm -f   
	rm -f *.o 
	rm -rf *.dSYM  
	rm -f *~



 
