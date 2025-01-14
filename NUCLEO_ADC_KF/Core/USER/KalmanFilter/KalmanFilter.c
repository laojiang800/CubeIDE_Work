
#include "KalmanFilter.h"

float LastStandardDev = 10;
float LastAverage = 0;

float calculateAverage(uint32_t *buf, uint8_t size) {
    uint32_t Sum = 0;
    for (uint8_t i = 0; i < size; i++) {
        Sum += buf[i];
    }
    return (float)Sum / size;
}

float calculateSD(uint32_t *buf, uint8_t size) {
    float Average = calculateAverage(buf, size);
    float variance = 0;
    for(uint8_t i = 0; i < size; i++) {
        variance += pow((float)buf[i] - Average, 2);
    }
    return sqrt(variance / size);
}

float KalmanFilter(uint32_t *buf, uint8_t size) {
    float ObservAverage = calculateAverage(buf, size);
    float ObservStandardDev = calculateSD(buf, size);
    float PredicStandardDev;
    float Kalmancoef;
    float Kalmanoutput;
    PredicStandardDev = sqrt(pow(LastStandardDev, 2) + 3 * 3);
    Kalmancoef = pow(PredicStandardDev, 2) / (pow(PredicStandardDev, 2) + pow(ObservStandardDev, 2));
    Kalmanoutput = LastAverage + Kalmancoef * (ObservAverage - LastAverage);
    LastAverage = Kalmanoutput;
    LastStandardDev = sqrt((1 - Kalmancoef) * pow(PredicStandardDev, 2));
    return Kalmanoutput;
}

