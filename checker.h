#ifndef CHECKER_H
#define CHECKER_H

// Function declarations
int batteryIsOk(float temperature, float soc, float chargeRate);
void display(const char* message);
int checkCondition(float value, float min, float max, const char* message);
int checkSocWarning(float value, float min, float max);
int checkChargeRateWarning(float chargeRate);
int checkTemperatureWarning(float temperature, float min, float max);

#endif // CHECKER_H
