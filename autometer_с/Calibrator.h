#pragma once
class Calibrator
{
public:
	Calibrator(void);
	int setVoltage(double volt);
	int setFrequency(double hz);
	int setTrigger(bool trigger);
	double Uout;
	double Fout;
private:
	int send(char *str);

};

