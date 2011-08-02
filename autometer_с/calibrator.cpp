#include "StdAfx.h"
#include "calibrator.h"
#include <stdio.h>


Calibrator::Calibrator(void)
{
}

int Calibrator::setVoltage(double volt)
{
	char str[255];
	sprintf(str,"V => %f",volt);
	send(str);
	return 0;
}

int Calibrator::setFrequency(double hz)
{
	char str[255];
	sprintf(str,"F => %f",hz);
	send(str);
	return 0;
}

int Calibrator::setTrigger(bool trigger)
{
	if(trigger)
		send("T => 1");
	else
		send("T => 0");
	return 0;
}
int Calibrator::send(char *str)
{
	printf("%s\n",str);
	return 0;
}