#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
  if (temperature < TEMP_MIN || temperature > TEMP_MAX) {
    printf("Temperature out of range!\n");
  if (soc < SOC_MIN || soc > SOC_MAX) {
    printf("State of Charge out of range!\n");
  if (chargeRate > CHARGE_RATE_MAX) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
