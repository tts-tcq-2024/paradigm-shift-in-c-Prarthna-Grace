#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
  if (temperature < TEMP_MINi || temperature > TEMP_MAXi) {
    printf("Temperature out of range!\n");
    return 0;
  }
  if (soc < SOC_MINi || soc > SOC_MAXi) {
    printf("State of Charge out of range!\n");
    return 0;
  }
  if (chargeRate > CHARGE_RATE_MAXi) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(35, 95, 0));
}
