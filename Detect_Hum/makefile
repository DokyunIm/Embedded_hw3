hum: get_humidity.o dcmotoron.o fanon.o rgbon.o
	gcc -o hum get_humidity.o dcmotoron.o fanon.o rgbon.o -lwiringPi -lpthread

get_humidity.o:
	gcc -O -c get_humidity.c

dcmotoron.o:
	gcc -O -c dcmotoron.c

fanon.o:
	gcc -O -c fanon.c

rgbon.o:
	gcc -O -c rgbon.c

clean:
	rm -f get_humidity.o dcmotoron.o fanon.o rgbon.o hum
