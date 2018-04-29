#include <signal.h> //Signal 사용 헤더파일
#include <unistd.h>
#include <stdio.h> 
#include <string.h> 
#include <errno.h>
#include <stdlib.h> //exit() 사용 헤더파일

#include <wiringPi.h>
#include "detectTemperature.h"
#define PUMP	21 // BCM_GPIO 5

void exit_pump(int signo); // 마지막 종료 함수

void *pumpon(void *arg)
{
	
	if (wiringPiSetup () == -1)
	{
		fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno));
		return NULL;
	}

	pinMode (PUMP, OUTPUT) ;
	
	printf("pump on\n");
	digitalWrite (PUMP, 1) ; // On
	
	delay (1000) ; // ms
	
	digitalWrite (PUMP, 0) ; // Off
	
	delay (1000) ;
	

	return NULL;
}

void exit_pump(int signo)
{
    printf("process stop\n");
	digitalWrite (PUMP, 0) ; // Off
	
} 



