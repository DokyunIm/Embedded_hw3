#include <signal.h> //Signal 사용 헤더파일
#include <unistd.h>
#include <stdio.h> 
#include <string.h> 
#include <errno.h>
#include <stdlib.h> //exit() 사용 헤더파일
#include <softPwm.h>
#include <wiringPi.h>
#include "detectHum.h"

#define DCMOTOR	23 // BCM_GPIO 13

void exit_dc(int signo);

void *control_dc(void *arg)
{
	
	if (wiringPiSetup () == -1)
	{
		fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno));
		return NULL ;
	}

	pinMode (DCMOTOR, OUTPUT) ;
	printf("here - DCMOTOR on\n");
	softPwmCreate(DCMOTOR, 0, 100);
	softPwmWrite(DCMOTOR, 5);
	delay(2000);
	digitalWrite(DCMOTOR, 0);
	return NULL;
}

void exit_dc(int signo){
	printf("turn off dc\n");
	digitalWrite(DCMOTOR, 0);
}
