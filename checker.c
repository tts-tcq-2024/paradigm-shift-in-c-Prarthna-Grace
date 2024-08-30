#include <stdio.h>
#include <assert.h>


int batteryIsOk(float temperature, float soc, float chargeRate) {
    BatteryParameter parameters[] = {
        {temperature, (temperature < 0 || temperature > 45), "Temperature out of range!\n"},
        {soc, (soc < 20 || soc > 80), "State of Charge out of range!\n"},
        {chargeRate, (chargeRate > 0.8), "Charge Rate out of range!\n"}
    };

    int isOk = 1;

    for (int i = 0; i < 3; i++) {
        if (parameters[i].isOutOfRange) {
            printf("%s", parameters[i].message);
            isOk = 0;
        }
    }

    return isOk;
}
int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
