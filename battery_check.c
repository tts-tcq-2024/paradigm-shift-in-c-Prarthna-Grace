#include<stdio.h>
#include<checker.c>
#include<check_condition.c>

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int isokay = 1;

    isokay &= checkCondition(temperature, 0, 45, "Temperature out of range!\n");
    isokay &= checkCondition(soc, 20, 80, "State of Charge out of range!\n");
    
    if (chargeRate > 0.8) {
        display("Charge Rate out of range!\n");
        isokay = 0;
    }

    return isokay;
}
