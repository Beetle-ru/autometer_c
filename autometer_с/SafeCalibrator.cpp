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
	if(Fout != Frequency) //���������� �� 0 ���� ���������� �������
		Uout = 0;
	if(Voltage*Uout<0) // ���������� �� 0 ���� ��������� ���� ����������
		Uout = 0;
	setFrequency(Frequency);
	setVoltage(Uout);
	setTrigger(1);
	while(fabs((Voltage-Uout)*k)>0.0000001) // ������ ���� �� ��������� ����������� �����
	{
		Sleep(100); // �������� 100 ����������
		setVoltage(Uout); // ������������� ���������� �� ������ �����������
		if(fabs((Voltage-Uout)*k)<100)
			Uout+=((Voltage-Uout)*k);
		else
			Uout+=((Voltage-Uout)*0.1);
	}
	return 0;
}