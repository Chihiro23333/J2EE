encrypt.o:encrypt.c encrypt.h
	gcc -c -I. encrypt.c -o encrypt.o
	
checksum.o:checksum.c checksum.h
	gcc -c -I. checksum.c -o checksum.o
	
bank.o:bank.c encrypt.h checksum.h
	gcc -c -I. bank.c -o bank.o
	
libencrypt.a:encrypt.o checksum.o
	ar -rcs libencrypt.a encrypt.o checksum.o
	
bank:libencrypt.a bank.c
	gcc bank.c -I. -L. -lencrypt -o bank
	
bank1:encrypt.o checksum.o bank.c
	gcc bank.c -I. encrypt.o checksum.o -o bank1
	
bank2:libencrypt.a bank.o
	gcc bank.o -L. -lencrypt -o bank2