#include <signal.h> //Signal 사용 헤더파일
#include <unistd.h>
#include <stdio.h> 
#include <string.h> 
#include <errno.h>
#include <stdlib.h> //exit() 사용 헤더파일

#include <wiringPi.h>
#include "detectHum.h"
#define FAN	22 // BCM_GPIO 6

void exit_fan(int signo);

void *control_fan(void *arg)
{
	//signal(SIGINT, (void *)sig_handler);	//시그널 핸들러 함수
	
	if (wiringPiSetup () == -1)
	{
		fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno));
		return NULL;
	}

	pinMode (FAN, OUTPUT) ;

	printf("here - FAN on\n");
	digitalWrite (FAN, 1) ; // On		
	delay(2000);
	digitalWrite(FAN,0);
	return NULL;
}

void exit_fan(int signo){
	printf("turn off fan\n");
	digitalWrite(FAN, 0);
}

