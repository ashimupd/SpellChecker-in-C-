spellcheck : spellcheck.o readfromdict.o getline.o ldistance.o
	   gcc -o spellcheck spellcheck.o readfromdict.o getline.o ldistance.o

spellcheck.o : spellcheck.c readfromdict.h
	     gcc -c spellcheck.c

getline.o :  getline.c
	  gcc -c getline.c

ldistance.o : ldistance.c
	 gcc -c ldistance.c

readfromdict.o : readfromdict.c ldistance.h getline.h
	       gcc -c readfromdict.c

all : spellcheck

clean :
	 rm -f spellcheck.o readfromdict.o getline.o ldistance.o spellcheck

tarball : spellcheck spellcheck.c getline.c ldistance.c readfromdict.c readfromdict.h ldistance.h getline.h makefile
	tar -c -f spellcheck.tar spellcheck spellcheck.c getline.c ldistance.c readfromdict.c readfromdict.h ldistance.h getline.h makefile
