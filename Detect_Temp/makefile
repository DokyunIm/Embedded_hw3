temper: get_temperature.o pumpon.o
	gcc -o temper get_temperature.o pumpon.o -lwiringPi -lpthread

get_temperature.o: get_temperature.c
	gcc -O -c get_temperature.c

pumpon.o: pumpon.c
	gcc -O -c pumpon.c

clean:
	rm -f get_temperature.o pumpon.o temper
