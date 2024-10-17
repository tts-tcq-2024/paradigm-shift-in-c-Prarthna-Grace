#include <stdio.h>
#include <assert.h>
#include<battery_checck.c>
#include<check_condition.c>

void display(const char* message){
    printf("%s", message);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));  
  assert(!batteryIsOk(50, 85, 0));  
  assert(!batteryIsOk(25, 85, 0));   
  assert(!batteryIsOk(50, 70, 0));  
  assert(!batteryIsOk(25, 70, 0.9)); 
  assert(!batteryIsOk(50, 80, 0.7)); 
}
