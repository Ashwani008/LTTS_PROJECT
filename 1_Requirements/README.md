# Requirements
## Introduction
 ### Why do we need TIMERS?
  * TIMERS help in scheduling the events to be triggered or fired in a software or an application in future for ONE SHOT or PERIODICALLY.
  * TIMERS  are extensively used in many domains of Computer Science, expecially in Networking. Some of the examples are, 
    #### TCP Timers.
     * Timer for scheduling an acknowledgement packet.
     * Timer to run its Back-off Algorithm.
    #### OTP Time Outs.
    #### Session Log Out.
    #### Periodically sending out Network Packets.
    #### Defining/ Scheduling the computation.
  * One of the most common programming concept that you would come across is TIMERS.
 ### Types of TIMERS
  #### 1. ONE SHOT TIMERS
   * These are used when a Application needs to do some work only once in future.
   * They are triggered only once.
   * For Example, Delete X after 10 sec.
  #### 2. PERIODIC TIMERS
   * These are used when a Application needs to do some work periodically at regular intervals.
   * They are triggered at regular intervals.
   * For Example, Send HELLO at an interval of 5 sec for 100 sec.
  #### 3. EXPONENTIAL BACKOFF TIMERS
   * It is a special case of periodic timers.
   * They are triggered at exponentially placed temporal points.
   * Send re-entry event at t = 1, t = 2, t = 4, t = 8, t = 16, ..... so on.
   * Used in protocols such as TCP.
   
 LINUX Enabled APIs will provide us the basic foundations regarding how to implement a TIMER and then we will  uild up from there to design the TIMER library which will give the developer full control over timers.
 We will study about LINUX inbuilt POSIX compliant TIMER APIs and build our own custom more controllable TIMER Library on top of those.
 We will be implementing all the three types of TIMERS mentioned above.

## Research
 POSIX provides four basic APIs to manipulate timers on UNIX compliance platforms.
 
 * timer_create() -> Create a TIMER data structure(But do not fire it).
 * timer_settime() -> Used to start/stop the timers depending on the arguments.
 * timer_gettime() -> Returns the time remaining for the timer to fire.
 * timer_delete() -> Delete the TIMER data structure.
 
 We will be using the above 4 APIs as building blocks to build our own custom TIMER Library.
 
 ![Detailed Explanation of Research](Research_Timers.pdf)

 
