#include <stdio.h>
#include <assert.h>
#include"checker.h"

void display(const char* message){
    printf("%s", message);
}

int main() {
    // Normal case
    assert(batteryIsOk(25, 70, 0.7)); 
    // Temperature out of range
    assert(!batteryIsOk(50, 85, 0)); 
    // State of Charge out of range
    assert(!batteryIsOk(25, 85, 0)); 
     // Temperature out of range
    assert(!batteryIsOk(50, 70, 0));  
     // Charge rate out of range
    assert(!batteryIsOk(25, 70, 0.9)); 
    // Temperature out of range with valid SoC
    assert(!batteryIsOk(50, 80, 0.7));
    // Approaching discharge warning for SoC
    assert(batteryIsOk(25, 19.9, 0.7)); // Should be okay but with a warning
    // Approaching charge-peak warning for SoC
    assert(batteryIsOk(25, 79.9, 0.7)); // Should be okay but with a warning
    // Charge rate approaching maximum (0.75)
    assert(batteryIsOk(25, 70, 0.75)); // Should be okay but with a warning
}
