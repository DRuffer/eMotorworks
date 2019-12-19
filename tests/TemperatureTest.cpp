#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

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
        mock().clear();
    }
};

void controlDevicesTest()
{
    mock().actualCall("controlDevicesTest");
    controlDevices();
}

TEST(Temperature, returns_1)
{
    LONGS_EQUAL(4, getTemperatureFromRawSample());
    mock().expectOneCall("controlDevicesTest");
    controlDevicesTest();
    mock().checkExpectations();
}

