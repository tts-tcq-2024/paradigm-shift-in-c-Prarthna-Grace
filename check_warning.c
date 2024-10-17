#include<stdio.h>
#include<checker.h>

void display(const char* message) {
    printf("%s", message);
}

int checkWarning(float value, float min, float max) {
    float warningThreshold = 0.05 * max; // 5% of the max value
    if (value >= min && value < (min + warningThreshold)) {
        display("Warning: Approaching discharge\n");
        return 1; // Indicates a warning
    } else if (value <= max && value > (max - warningThreshold)) {
        display("Warning: Approaching charge-peak\n");
        return 1; // Indicates a warning
    }
    return 0; // No warning
}
