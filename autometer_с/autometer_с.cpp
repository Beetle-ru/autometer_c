 // autometer_с.cpp: главный файл проекта.

#include "stdafx.h"
#include "Calibrator.h"
#include "SafeCalibrator.h"
#include "voltmetr.h"
#include "major.h"
using namespace System;

int main(array<System::String ^> ^args)
{
	SafeCalibrator *cal = getSafeCalibrator();
    cal->runUpExact(1,0);
	//cal->runUpExact(2,0);
    return 0;
}
