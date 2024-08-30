#include <stdio.h>
#include <assert.h>

#include <stdio.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int status = 0;

    // Check temperature
    if (temperature < 0 || temperature > 45) {
        status |= 1; // Set bit 0
    }

    // Check state of charge
    if (soc < 20 || soc > 80) {
        status |= 2; // Set bit 1
    }
    // Check charge rate
    if (chargeRate > 0.8) {
        status |= 4; // Set bit 2
    }

    // Print messages based on status
    switch (status) {
        case 1: // Temperature out of range
            printf("Temperature out of range!\n");
            break;
        case 2: // State of Charge out of range
            printf("State of Charge out of range!\n");
            break;
             case 3: // Temperature and SOC out of range
            printf("Temperature out of range!\n");
            printf("State of Charge out of range!\n");
            break;
        case 4: // Charge Rate out of range
            printf("Charge Rate out of range!\n");
            break;
        case 5: // Temperature and Charge Rate out of range
            printf("Temperature out of range!\n");
            printf("Charge Rate out of range!\n");
            break;
        case 6: // SOC and Charge Rate out of range
            printf("State of Charge out of range!\n");
            printf("Charge Rate out of range!\n");
            break;
        case 7: // All conditions out of range
            printf("Temperature out of range!\n");
            printf("State of Charge out of range!\n");
            printf("Charge Rate out of range!\n");
            break;
        default: // All conditions are okay
            break;
    }
return status == 0;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
