#include <signal.h> //Signal 사용 헤더파일
#include <unistd.h>
#include <stdio.h> 
#include <string.h> 
#include <errno.h>
#include <stdlib.h> //exit() 사용 헤더파일

#include <wiringPi.h>
#include "detectHum.h"
#define RGBLEDPOWER  24 //BCM_GPIO 19

#define RED	7 //27
#define GREEN	9 //28
#define BLUE	8 //29

void exit_rgb(int signo);

void *control_rgb(void *arg)
{
	
	if (wiringPiSetup () == -1)
	{
		fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno));
		return NULL;
	}

	pinMode(RGBLEDPOWER, OUTPUT);
	pinMode(RED, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(BLUE, OUTPUT);
	
	//digitalWrite(RGBLEDPOWER, 1);
	digitalWrite(RED, 1);
	digitalWrite(BLUE, 0);
	digitalWrite(GREEN, 0);

	delay(2000);	
	
	digitalWrite(RED, 0);
	digitalWrite(BLUE, 0);
	digitalWrite(GREEN, 0);
	return NULL;
}

void exit_rgb(int signo){
	digitalWrite(RED, 0);
	digitalWrite(BLUE, 0);
	digitalWrite(GREEN, 0);
	
}
