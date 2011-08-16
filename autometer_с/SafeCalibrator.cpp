#include "StdAfx.h"
#include "SafeCalibrator.h"
#include <stdio.h>
#include <math.h>
#include <windows.h>
//
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
	if(Fout != Frequency) //сбрасываем на 0 если изменилась частота
		Uout = 0;
	if(Voltage*Uout<0) // сбрасываем на 0 если изменился знак напряжения
		Uout = 0;
	setFrequency(Frequency);
	setVoltage(Uout);
	setTrigger(1);
	while(fabs((Voltage-Uout)*k)>0.0000001) // крутим пока не достигнут минимальный порог
	{
		Sleep(100); // задержка 100 милисекунд
		setVoltage(Uout); // устанавливает напряжение на выходе калибратора
		if(fabs((Voltage-Uout)*k)<100)
			Uout+=((Voltage-Uout)*k);
		else
			Uout+=((Voltage-Uout)*0.1);
	}
	return 0;
}