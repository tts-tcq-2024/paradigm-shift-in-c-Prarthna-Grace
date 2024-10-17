#include<stdio.h>
#include<checker.h>

void display(const char* message) {
    printf("%s", message);
}

// Function to check if value is approaching discharge
int checkApproachingDischarge(float value, float min, float warningThreshold) {
    if (value >= min && value < (min + warningThreshold)) {
        display("Warning: Approaching discharge\n");
        return 1; // Indicates a warning
    }
    return 0; // No warning
}

// Function to check if value is approaching charge-peak
int checkApproachingChargePeak(float value, float max, float warningThreshold) {
    if (value <= max && value > (max - warningThreshold)) {
        display("Warning: Approaching charge-peak\n");
        return 1; // Indicates a warning
    }
    return 0; // No warning
}

// Function to check warnings for a value within a range
int checkWarning(float value, float min, float max) {
    float warningThreshold = 0.05 * max; // 5% of the max value

    // Check both conditions separately
    int warningTriggered = 0;
    warningTriggered |= checkApproachingDischarge(value, min, warningThreshold);
    warningTriggered |= checkApproachingChargePeak(value, max, warningThreshold);

    return warningTriggered; // Return 1 if any warning was triggered
}
// Function to check charge rate warning
int checkChargeRateWarning(float chargeRate) {
    float maxChargeRate = 0.8; // Assuming 0.8 is the maximum acceptable charge rate
    float warningThreshold = 0.05 * maxChargeRate; // 5% of the maximum charge rate

    if (chargeRate >= (maxChargeRate - warningThreshold) && chargeRate < maxChargeRate) {
        display("Warning: Approaching maximum charge rate\n");
        return 1; // Indicates a warning
    }
    
    return 0; // No warning
}
