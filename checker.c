#include <stdio.h>
#include <assert.h>

void display(const char* message){
    printf("%s", message);
}

int checkCondition(float value, float min, float max, const char* message) {
    if (value < min || value > max) {
        display(message);
        return 0;
    }
    return 1;
}

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

int main() {
  assert(batteryIsOk(25, 70, 0.7));  
  assert(!batteryIsOk(50, 85, 0));  
  assert(!batteryIsOk(25, 85, 0));   
  assert(!batteryIsOk(50, 70, 0));  
  assert(!batteryIsOk(25, 70, 0.9)); 
  assert(!batteryIsOk(50, 80, 0.7)); 
}
