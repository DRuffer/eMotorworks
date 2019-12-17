#include <stdio.h>
#include <stdint.h>
#include "../PhaseDelay-include/PhaseDelay.h"

// This array stores the collected samples from the ADC
// A huge speedup could be seen by also maintaining
// a running sum as samples are taken.
uint16_t raw_samples[256]; // The values are from 0 to 4096

void setRawSamples(int value) {
    for (int i = 0; i < 256; i++)
        raw_samples[i] = value;
}

/*
* This function processes the raw samples stored in raw_samples,
* and recovers the phase delay (theta).
*
* When the function is called, we assume that raw_samples
* already has the most up-to-date samples from the ADC.
*/
float getPhaseDelayFromRawSamples(void) {
    float theta = 1.0;
    uint32_t sum = 0;

    setRawSamples(4095); // for testing purposes

    for (int i = 0; i < 256; i++)
        sum += raw_samples[i];

    // 256 and 4096 divides can be done with shifts,
    // but I'd want to see timings on the target hardware
    theta = (((float)sum/256)/4096)*360;
    printf("sum = %d, theta = %f", sum, theta);

    return theta; // theta is between 0 and 360
}

// enable for stand alone testing
#if 0
int main(int ac, char** av) {
  return (int)getPhaseDelayFromRawSamples();
}
#endif
