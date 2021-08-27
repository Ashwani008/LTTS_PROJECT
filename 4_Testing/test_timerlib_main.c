
#include "unity.h"
#include "test_timerlib.h"

/**
 * @brief Set the Up object
 * Required by the unity test framework
 */
void setUp() {}

/**
 * @brief Release the objects that are setup for tests
 * Required by the unity test framework
 */
void tearDown() {}

Timer_t *timer = NULL;
static void
app_cb(Timer_t *timer, void *user_data){

	printf("User data = %s\n", (char *)user_data);
}

void test_timer_creation()
{
    char *name = "Ashwani";
    timer = setup_timer(app_cb, 1000 , 0, 1, name, false);
    TEST_ASSERT_NOT_EQUAL(NULL, timer);
}

void test_start_timer()
{
    
    TEST_ASSERT_EQUAL(SUCCESS,start_timer(timer));
}

void test_pause_timer()
{
    
    TEST_ASSERT_EQUAL(SUCCESS,pause_timer(timer));
}

void test_resume_timer()
{
    
    TEST_ASSERT_EQUAL(SUCCESS,resume_timer(timer));
}

void test_restart_timer()
{
    
    TEST_ASSERT_EQUAL(SUCCESS,restart_timer(timer));
}

void test_rescheduled_timer()
{
    TEST_ASSERT_EQUAL(SUCCESS, reschedule_timer(timer, timer->exp_timer, timer->sec_exp_timer));
}

void test_delete_timer()
{
    
    TEST_ASSERT_EQUAL(SUCCESS,delete_timer(timer));
}

void test_cancel_timer()
{
    
    TEST_ASSERT_EQUAL(SUCCESS,cancel_timer(timer));
}

void test_get_remaining_time()
{
    unsigned long ret_val = timer_get_time_remaining_in_mill_sec(timer);
    TEST_ASSERT_EQUAL(-1,ret_val);
}

void test_print()
{
    TEST_ASSERT_EQUAL(SUCCESS,print_timer(timer));
}

int main(void)
{
  
  /* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  /* Run Test functions */
  RUN_TEST(test_timer_creation);
    RUN_TEST(test_start_timer);
    RUN_TEST(test_pause_timer);
    RUN_TEST(test_resume_timer);
    RUN_TEST(test_restart_timer);
    RUN_TEST(test_rescheduled_timer);
    RUN_TEST(test_delete_timer);
    RUN_TEST(test_cancel_timer);
    RUN_TEST(test_get_remaining_time);
    RUN_TEST(test_print);
  /* Close the Unity Test Framework */
  return UNITY_END();
	//end
}
