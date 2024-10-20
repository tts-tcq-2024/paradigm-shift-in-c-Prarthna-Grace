#include<stdio.h>
#include"checker.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int isokay = 1;

     // Check temperature and display warnings if needed
    isokay &= checkCondition(temperature, 0, 45, "Temperature out of range!\n");
   checkTemperatureWarning(temperature, 0, 45);
    
     // Check SoC and display warnings if needed
    isokay &= checkCondition(soc, 20, 80, "State of Charge out of range!\n");
    checkSocWarning(soc, 20, 80);

    // Check charge rate and warning
    checkChargeRateWarning(chargeRate);

    // Check for charge rate out of range
    if (chargeRate > 0.8) {
        display("Charge Rate out of range!\n");
        isokay = 0;
    }

    return isokay; // Return 1 if all conditions are met, otherwise 0
}
