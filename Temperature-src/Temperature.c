#include <stdint.h>
#include "Temperature.h"

// This variable stores latest value from temperature sensor sampled by ADC
volatile uint16_t raw_adc_sample;

/*
* This function processes the raw ADC data and turns ON/OFF devices
* based on the it.
* When the function is called, we assume that raw_adc_sample
* already has the latest sample from the ADC.
*/
uint16_t getTemperatureFromRawSample(void)
{
    uint16_t degC = 1;

// TODO: Please implement this function
    return degC; // degC is between 0 to 100
}

/*
* This function turns ON/OFF devices based on temperature.
* as returned by getTemperatureFrom RawSample()
*/
void controlDevices(void)
{
// TODO: Please implement this function
}
