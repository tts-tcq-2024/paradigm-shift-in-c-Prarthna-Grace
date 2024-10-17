#include<stdio.h>
#include<checker.h>


void display(const char* message) {
    printf("%s", message);
}

int checkCondition(float value, float min, float max, const char* message) {
    if (value < min || value > max) {
        display(message);
        return 0;
    }
    return 1;
}
