
#ifndef __TIMER_WRAP__
#define __TIMER_WRAP__

#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum{

	TIMER_INIT,
	TIMER_DELETED,
	TIMER_PAUSED,
	TIMER_CANCELLED,
	TIMER_RESUMED,
	TIMER_RUNNING,
} TIMER_STATE_T;

typedef enum{
    SUCCESS,
    FAILURE,
}RET;

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


static inline void
timer_delete_user_data(Timer_t *timer){

	if(timer->user_arg) {
		free(timer->user_arg);
		timer->user_arg = NULL;
	}
}

static inline TIMER_STATE_T
timer_get_current_state(Timer_t *timer){

    return timer->timer_state;
}

static inline void
timer_set_state(Timer_t *timer, TIMER_STATE_T timer_state){

    timer->timer_state = timer_state;
    return SUCCESS;
}

void
resurrect_timer(Timer_t *timer);

RET
start_timer(Timer_t *timer);


RET
delete_timer(Timer_t *timer);

RET
cancel_timer(Timer_t *timer);

RET
pause_timer(Timer_t *timer);

RET
resume_timer(Timer_t *timer);

int
execute_timer(Timer_t *timer, TIMER_STATE_T action);

/* get remaining time in msec */
unsigned long
timer_get_time_remaining_in_mill_sec(Timer_t *timer);

RET
restart_timer(Timer_t *timer);

RET 
reschedule_timer(Timer_t *timer,
				unsigned long exp_ti,
				unsigned long sec_exp_ti);

RET
print_timer(Timer_t *timer);

unsigned long
timespec_to_millisec(
    struct timespec *time);

void
timer_fill_itimerspec(struct timespec *ts,
                      unsigned long msec);

bool
is_timer_running(Timer_t *timer);


#endif /* __TIMER_WRAP__  */