#include <unity.h>
#include <hardware/Simulated.h>

#include <chrono>
#include <iostream>

void setUp(void)
{
}

void tearDown(void)
{
}

void Expect_test_to_compile()
{
}

void Expect_hardware_to_be_able_to_sleep_for_some_ms()
{
  hardware::Hardware<hardware::Simulated> hw;
  
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    hw.sleepMs(250);
    end = std::chrono::system_clock::now();
 
    int elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>
                             (end-start).count();
 
    TEST_ASSERT(250 == elapsed_ms);
}
   
int main(int, char **)
{
    UNITY_BEGIN();
    RUN_TEST(Expect_test_to_compile);
    RUN_TEST(Expect_hardware_to_be_able_to_sleep_for_some_ms);

    return UNITY_END();
}
