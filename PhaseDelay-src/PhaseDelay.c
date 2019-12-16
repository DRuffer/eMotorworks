#include "PhaseDelay.h"
#include <stdint.h>

// This array stores the collected samples from the ADC
uint16_t raw_samples[256]; // The values are from 0 to 4096

/*
* This function processes the raw samples stored in raw_samples,
* and recovers the phase delay (theta).
*
* When the function is called, we assume that raw_samples
* already has the most up-to-date samples from the ADC.
*/
int getPhaseDelayFromRawSamples(void) {
  int theta = 1; // TODO: Restore to returning a float

 // TODO: Please implement this function
 return theta; // theta is between 0 and 360
}
