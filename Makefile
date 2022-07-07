# -*- MakeFile -*-

verteilung: main_aufgabe2.o staticlib
	gcc main_aufgabe2.c -lstatistic -o verteilung

staticlib: 
	gcc getAvg.c getStddev.c readStream.c -c
	ar -crs libstatistic.a getAvg.o getStddev.o readStream.o
	sudo cp summarystats.h /usr/include
	sudo cp libstatistic.a /usr/lib
