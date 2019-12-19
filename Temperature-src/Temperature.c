#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../Temperature-include/Temperature.h"

// This variable stores latest value from temperature sensor sampled by ADC
volatile uint16_t raw_adc_sample;

void digitalWrite(int pin, int value) { // use Arduino model
  printf("GPIO %d set to %d\n", pin, value);
}

/*
* This function processes the raw ADC data and turns ON/OFF devices
* based on the it.
* When the function is called, we assume that raw_adc_sample
* already has the latest sample from the ADC.
*/
uint16_t getTemperatureFromRawSample(void)
{
    uint16_t degC = 1;

    raw_adc_sample = 51; // for testing purposes

    degC = raw_adc_sample * 100 / 1024;
    return degC; // degC is between 0 to 100
}

/*
* This function turns ON/OFF devices based on temperature.
* as returned by getTemperatureFrom RawSample()
*/
void controlDevices(void)
{
    if (raw_adc_sample > hot) {
        digitalWrite(FanGPIO, true);
    } else {
        digitalWrite(FanGPIO, false);
    }
    if (raw_adc_sample < cold) {
        digitalWrite(HeatGPIO, true);
    } else {
        digitalWrite(HeatGPIO, false);
    }
}

// enable for stand alone testing
#if 1
int main(int ac, char** av) {
    int RawSample = getTemperatureFromRawSample();
    controlDevices();
    return RawSample;
}
#endif
