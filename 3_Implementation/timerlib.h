/**
 * @file timerlib.h
 * @author Ashwani Kumar Dubey (ashwani26061999@gmail.com)
 * @brief Implementation of Timer
 * @version 0.1
 * @date 2021-07-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TIMER_WRAP__
#define __TIMER_WRAP__

#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * @brief Defines the state of timers
 * 
 */
typedef enum{

	TIMER_INIT,
	TIMER_DELETED,
	TIMER_PAUSED,
	TIMER_CANCELLED,
	TIMER_RESUMED,
	TIMER_RUNNING,
} TIMER_STATE_T;

/**
 * @brief Structure of Timer
 * 
 */
typedef struct Timer_{

	/* Timer config */
    timer_t posix_timer;
    void *user_arg;
	unsigned long exp_timer;		/* in milli-sec */
	unsigned long sec_exp_timer;	/* in milli-sec */
	uint32_t thresdhold;			/* No of times to invoke the timer callback */
	void (*cb)(struct Timer_ *, void *); /* Timer Callback  */
	bool exponential_backoff;

	/* place holder value to store
 	 * dynamic attributes of timer */
	unsigned long time_remaining;	/* Time left for paused timer for next expiration */
	uint32_t invocation_counter; 
	struct itimerspec ts;
	unsigned long exp_back_off_time;
	TIMER_STATE_T timer_state;
} Timer_t;

/**
 * @brief Create Timer and configure it's attribute
 * @return Returns NULL in timer creation fails, else return a pointer to Timer object 
 * 
 */
/* Returns NULL in timer creation fails, else
 * return a pointer to Timer object*/
Timer_t*
setup_timer(
    void (*timer_cb)(Timer_t*, void *), /*   Timer Callback with user data*/
    unsigned long exp_timer,            /*   First expiration time interval in msec */
    unsigned long sec_exp_timer,        /*   Subsequent expiration time interval in msec */
    uint32_t threshold,                 /*   Max no of expirations, 0 for infinite*/
    void *user_arg,                     /*   Arg to timer callback */
    bool exponential_backoff);          /*   Is Timer Exp backoff*/


/**
 * @brief DELETE timer
 * 
 * @param timer 
 */
static inline void
timer_delete_user_data(Timer_t *timer){

	if(timer->user_arg) {
		free(timer->user_arg);
		timer->user_arg = NULL;
	}
}

/**
 * @brief Get the Current State of timer
 * 
 * @param timer 
 * @return TIMER_STATE_T 
 */
static inline TIMER_STATE_T
timer_get_current_state(Timer_t *timer){

    return timer->timer_state;
}

/**
 * @brief Set the State of timer
 * 
 * @param timer 
 * @param timer_state 
 */
static inline void
timer_set_state(Timer_t *timer, TIMER_STATE_T timer_state){

    timer->timer_state = timer_state;
}

/**
 * @brief Reset or Resurrect the timer
 * 
 * @param timer 
 */
void
resurrect_timer(Timer_t *timer);

/**
 * @brief Start the timer
 * 
 * @param timer 
 */
void
start_timer(Timer_t *timer);

/**
 * @brief Delete the timer
 * 
 * @param timer 
 */
void
delete_timer(Timer_t *timer);

/**
 * @brief Cancels the Timer
 * 
 * @param timer 
 */
void
cancel_timer(Timer_t *timer);

/**
 * @brief Paused the Timer
 * 
 * @param timer 
 */
void
pause_timer(Timer_t *timer);

/**
 * @brief Resumes the Timer
 * 
 * @param timer 
 */
void
resume_timer(Timer_t *timer);

/**
 * @brief Executes the Timer
 * 
 * @param timer 
 * @param action 
 * @return int 
 */
int
execute_timer(Timer_t *timer, TIMER_STATE_T action);

/**
 * @brief Get remaining time in msec
 * 
 * @param timer
 * @return unsigned long
 * 
 */
/* get remaining time in msec */
unsigned long
timer_get_time_remaining_in_mill_sec(Timer_t *timer);

/**
 * @brief Restart the Timer
 * 
 * @param timer 
 */
void
restart_timer(Timer_t *timer);

/**
 * @brief Rechedule the Timer
 * 
 * @param timer 
 * @param exp_ti 
 * @param sec_exp_ti 
 */
void 
reschedule_timer(Timer_t *timer,
				unsigned long exp_ti,
				unsigned long sec_exp_ti);

/**
 * @brief Print the details of Timer
 * 
 * @param timer 
 */
void
print_timer(Timer_t *timer);

/**
 * @brief convert the time to millisecond
 * 
 * @param time 
 * @return unsigned long 
 */
unsigned long
timespec_to_millisec(
    struct timespec *time);

/**
 * @brief Configure the Timer or Change the Type of Timer
 * 
 * @param ts 
 * @param msec 
 */
void
timer_fill_itimerspec(struct timespec *ts,
                      unsigned long msec);

/**
 * @brief Check whether the timer is running or not
 * 
 * @param timer 
 * @return true 
 * @return false 
 */
bool
is_timer_running(Timer_t *timer);


#endif /* __TIMER_WRAP__  */