# TEST PLAN:

## Table no: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  HR_01_01       |Check if Timer is created or not                        | (1).Timer Callback with user data  (2). First expiration time interval in msec (3). Subsequent expiration time interval in msec (4). Max no of expirations (5). Arg to timer callback (6). Is Timer Exp backoff | Pointer to Timer | PASS | Requirement based|
|  H_01_02       |Check Timer is started or not                           | (1). Pointer to Timer | SUCCESS |PASS|Requirement based |
| HR_01   |Check Timer is Paused or not | (1). Pointer to Timer | SUCCESS |PASS|Requirement based |
| HR_02 | Check Timer is Resumed or not | (1). Pointer to Timer  | SUCCESS | PASS | Requirement based |
| HR_03 | Check Timer is Restart or not | (1). Pointer to Timer | SUCCESS | PASS | Requirement based |
| HR_04 | Check timer is Rescheduled or not | (1). Pointer to Timer (2).First expiration time interval in msec (3). Subsequent expiration time interval in msec  | SUCCESS | PASS | Requirement based |
| HR_05 | Check timer is Deleted or not | (1). Pointer to Timer | SUCCESS | PASS | Requirement based |
| HR_06 | Check Timer is Canceled or not | (1). Pointer to Timer | SUCCESS | PASS  | Requirement based |
| HR_07 | Check Remaining time for expiration of timer | (1). Pointer to Timer | Time in millisecond | PASS | Requirement based |
| HR_08 | Display the Timer Details | (1). Pointer to timer | SUCCESS | PASS | Requirement based |

