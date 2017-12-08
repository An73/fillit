all: *.c
	gcc -c *.c -Ifillit.h
	gcc *.o -o fillit

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f fillit

re: fclean all
