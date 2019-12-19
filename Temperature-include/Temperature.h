#ifndef TEMPERATURE_INCLUDED
#define TEMPERATURE_INCLUDED

#define FanGPIO 10
#define HeatGPIO 11
#define hot 522
#define cold 52

void digitalWrite(int pin, int value);

uint16_t getTemperatureFromRawSample(void);
void controlDevices(void);

#endif

