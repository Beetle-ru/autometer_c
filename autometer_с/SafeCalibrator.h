#pragma once
#include "calibrator.h"
//
class SafeCalibrator :
	public Calibrator
{
public:
	SafeCalibrator(void);
	~SafeCalibrator(void);
	int runUpExact(double Voltage, double Frequency);
};

