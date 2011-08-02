#include "StdAfx.h"
#include "SafeCalibrator.h"
#include <stdio.h>
#include <math.h>


SafeCalibrator::SafeCalibrator(void)
{
}


SafeCalibrator::~SafeCalibrator(void)
{
}

int SafeCalibrator::runUpExact(double Voltage, double Frequency)
{
	const double k = 0.3333333333333333;
	setTrigger(0);
	setFrequency(Frequency);
	Uout = 0; // сбрасываем на ноль // доработать - сделать сброс только если изменилась частота или полярность
	setVoltage(Uout);
	setTrigger(1);
	while(fabs((Voltage-Uout)*k)>0.0000001) // крутим пока не достигнут минимальный порог
	{
		//sleepm(50) // задержка 50 милисекунд
		setVoltage(Uout); // устанавливает напряжение на выходе калибратора
		if(fabs((Voltage-Uout)*k)<100)
			Uout+=((Voltage-Uout)*k);
		else
			Uout+=((Voltage-Uout)*0.1);
	}
	return 0;
}