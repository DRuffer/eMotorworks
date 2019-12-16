#include "CppUTest/TestHarness.h"

extern "C"
{
#include "Temperature.h"
}

TEST_GROUP(Temperature)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(Temperature, returns_1)
{
    LONGS_EQUAL(1, getTemperatureFromRawSample());
}

