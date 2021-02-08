CC=gcc

out: main.o hashtable.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $^

clean:
	rm *.o out.exe