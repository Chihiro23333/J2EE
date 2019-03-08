birthday.o:birthday.c birthday.h
	gcc -c birthday.c
age.o:age.c birthday.h
	gcc -c age.c
age:birthday.o age.o
	gcc birthday.o age.o -o age