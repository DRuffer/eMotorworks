#include "CppUTest/TestHarness.h"

extern "C"
{
#include "PhaseDelay.h"
}

TEST_GROUP(PhaseDelay)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(PhaseDelay, returns_1)
{
    DOUBLES_EQUAL(1.0, getPhaseDelayFromRawSamples(), .01);
}

