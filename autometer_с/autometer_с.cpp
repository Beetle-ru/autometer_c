// autometer_с.cpp: главный файл проекта.

#include "stdafx.h"
#include "Calibrator.h"
#include "SafeCalibrator.h"
#include "voltmetr.h"
using namespace System;

int main(array<System::String ^> ^args)
{
	SafeCalibrator cal;
    cal.runUpExact(1,0);
    return 0;
}
