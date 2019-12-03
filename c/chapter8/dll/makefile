hfcal.o:hfcal.c
	gcc -IE:/C/J2EE/c/chapter8/dll/include -fPIC -c hfcal.c -o hfcal.o
hfcalchina.o:hfcalchina.c
	gcc -IE:/C/J2EE/c/chapter8/dll/include -fPIC -c hfcalchina.c -o hfcalchina.o
run.o:run.c
	gcc -IE:/C/J2EE/c/chapter8/dll/include -c run.c -o run.o
hfcal.dll:hfcal.o
	gcc -shared hfcal.o -o E:/C/J2EE/c/chapter8/dll/libhfcal.dll
hfcalchina.dll:hfcalchina.o
	gcc -shared hfcalchina.o -o E:/C/J2EE/c/chapter8/dll/libhfcal.dll
run.exe:hfcal.dll run.o
	gcc run.o -L. -lhfcal -o run
