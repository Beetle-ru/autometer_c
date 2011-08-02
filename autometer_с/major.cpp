#include "stdafx.h"
#include "Calibrator.h"
#include "SafeCalibrator.h"
#include "voltmetr.h"
#include "major.h"

//enum tvoltmetr {EMPTY,REFERNCE,VERIFIED};

Calibrator* getCalibrator()
{
	static Calibrator *pcal = new Calibrator();
	return pcal;
}
SafeCalibrator* getSafeCalibrator()
{
	static SafeCalibrator *pcal = new SafeCalibrator();
	return pcal;
}
Voltmetr* getVoltmetr(tvoltmetr tv)
{
	if(tv == EMPTY)
	{
		return 0;
	}
	if(tv == REFERNCE)
	{
		static Voltmetr *prefvolt = new Voltmetr();
		return prefvolt;
	}
	if(tv == VERIFIED)
	{
		static Voltmetr *pvervolt = new Voltmetr();
		return pvervolt;
	}
	return 0;
}