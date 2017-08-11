
t9: t9.o trie.o
	gcc -g -Wall -std=gnu99 -o t9 t9.o trie.o

t9.o: header.h t9.c
	gcc -g -Wall -std=gnu99 -c t9.c
    
trie.o: header.h trie.c
	gcc -g -Wall -std=gnu99 -c trie.c

clean:
	rm -f *.o bench *~
