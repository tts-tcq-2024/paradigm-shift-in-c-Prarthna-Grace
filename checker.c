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

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
