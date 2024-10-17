#ifndef CHECKER_H
#define CHECKER_H

// Function declarations
int batteryIsOk(float temperature, float soc, float chargeRate);
void display(const char* message);
int checkCondition(float value, float min, float max, const char* message);
int checkWarning(float value, float min, float max);
int checkChargeRateWarning(float chargeRate);

#endif // CHECKER_H
