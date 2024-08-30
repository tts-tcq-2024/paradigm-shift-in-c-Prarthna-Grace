#include <stdio.h>
#include <assert.h>

int checkCondition(float value, float min, float max, const char* message) {
    if (value < min || value > max) {
        printf("%s\n", message);
        return 0;
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    if (!checkCondition(temperature, 0, 45, "Temperature out of range!")) {
        return 0;
    }
    if (!checkCondition(soc, 20, 80, "State of Charge out of range!")) {
        return 0;
    }
    if (chargeRate > 0.8) {
        printf("Charge Rate out of range!\n");
        return 0;
    }
    return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(25, 85, 0));
  assert(!batteryIsOk(50, 70, 0));
  assert(!batteryIsOk(50, 80, 0.7));
}
