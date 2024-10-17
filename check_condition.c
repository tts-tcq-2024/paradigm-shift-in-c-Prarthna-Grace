#include<stdio.h>
#include<checker.c>

int checkCondition(float value, float min, float max, const char* message) {
    if (value < min || value > max) {
        display(message);
        return 0;
    }
    return 1;
}
