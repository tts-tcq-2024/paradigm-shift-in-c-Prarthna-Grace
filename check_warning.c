#include<stdio.h>
#include"checker.h"

// Function to check if temperature is approaching low threshold (discharge)
int checkApproachingLowTemperature(float temperature, float min, float warningThreshold_min) {
    if (temperature >= min && temperature < (min + warningThreshold_min)) {
        display("Warning: Approaching minimum temperature\n");
        return 1; // Indicates a warning
    }
    return 0; // No warning
}

// Function to check if temperature is approaching high threshold (charge-peak)
int checkApproachingHighTemperature(float temperature, float max, float warningThreshold_max) {
    if (temperature <= max && temperature > (max - warningThreshold_max)) {
        display("Warning: Approaching maximum temperature\n");
        return 1; // Indicates a warning
    }
    return 0; // No warning
}

// Function to check warnings for temperature
int checkTemperatureWarning(float temperature, float min, float max) {
    float warningThreshold_max = 0.05 * max; // 5% of the max value
    float warningThreshold_min = 0.05 * min; // 5% of the min value
    
    // Check both conditions separately
    int warningTriggered = 0;
    warningTriggered |= checkApproachingLowTemperature(temperature, min, warningThreshold_min);
    warningTriggered |= checkApproachingHighTemperature(temperature, max, warningThreshold_max);

    return warningTriggered; // Return 1 if any warning was triggered
}

// Function to check if value is approaching discharge
int checkApproachingDischarge(float value, float min, float warningThreshold_min) {
    if (value >= min && value < (min + warningThreshold_min)) {
        display("Warning: Approaching discharge\n");
        return 1; // Indicates a warning
    }
    return 0; // No warning
}

// Function to check if value is approaching charge-peak
int checkApproachingChargePeak(float value, float max, float warningThreshold_max) {
    if (value <= max && value > (max - warningThreshold_max)) {
        display("Warning: Approaching charge-peak\n");
        return 1; // Indicates a warning
    }
    return 0; // No warning
}

// Function to check warnings for a value within a range
int checkSocWarning(float value, float min, float max) {
    float warningThreshold_max = 0.05 * max; // 5% of the max value
    float warningThreshold_min = 0.05 * min; // 5% of the min value
    
    // Check both conditions separately
    int warningTriggered = 0;
    warningTriggered |= checkApproachingDischarge(value, min, warningThreshold_min);
    warningTriggered |= checkApproachingChargePeak(value, max, warningThreshold_max);

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
