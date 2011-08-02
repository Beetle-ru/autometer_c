#include "stdafx.h"
#include "Calibrator.h"
#include "SafeCalibrator.h"
#include "voltmetr.h"

enum tvoltmetr {EMPTY,REFERNCE,VERIFIED};

Calibrator* getCalibrator();

SafeCalibrator* getSafeCalibrator();

Voltmetr* getVoltmetr(tvoltmetr tv);
