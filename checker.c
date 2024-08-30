#include <stdio.h>
#include <assert.h>

int checkCondition(float value, float min, float max, const char* message) {
    if (value < min || value > max) {
        printf("%s", message);
        return 0;
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int a= checkCondition(temperature, 0, 45, "Temperature out of range!");
    
    int b = checkCondition(soc, 20, 80, "State of Charge out of range!");
    
    if ((chargeRate > 0.8) {
        printf("Charge Rate out of range!\n");
        if( a==0 && b==0) return 0;
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
