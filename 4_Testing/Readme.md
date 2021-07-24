# TEST PLAN:

## Table no: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       |Check if Timer is created or not                        | (1).Timer Callback with user data  (2). First expiration time interval in msec (3). Subsequent expiration time interval in msec (4). Max no of expirations (5). Arg to timer callback (6). Is Timer Exp backoff | Pointer to Timer | PASS | Requirement based|
|  H_01_01       |Check Timwer is started or not                           | (1). Pointer to Timer | SUCCESS |PASS|Requirement based |
|  H_02   |Check Timer is Paused or not | (1). Pointer to Timer | SUCCESS |PASS|Requirement based |
| H_02_01 | Check Timer is Resumed or not | (1). Pointer to Timer  | SUCCESS | PASS | Requirement based |
| H_02_02 | Check Timer is Restart or not | (1). Pointer to Timer | SUCCESS | PASS | Requirement based |
| H_03 | Check timer is Rescheduled or not | (1). Pointer to Timer (2).First expiration time interval in msec (3). Subsequent expiration time interval in msec  | SUCCESS | PASS | Requirement based |
| H_03_01 | Check timer is Deleted or not | (1). Pointer to Timer | SUCCESS | PASS | Requirement based |
| H_04 | Check Timer is Canceled or not | (1). Pointer to Timer | SUCCESS | PASS  | Requirement based |
| H_05 | Check Remaining time for expiration of timer | (1). Pointer t | SUCCESS | SUCCESS | Requirement based |
| H_05_01 | Check if record is also updated in File | (1). File Pointer (2). Id | SUCCESS | SUCCESS | Technical |
| H_06 | Deleting Record | (1). Head pointer (2). Id | Pointer to Head node| PASS| Requirement based |
| H_06_01 | If record is only present in List, then delete from List | (1). Head pointer (2). Id | Pointer to head node | PASS | Technical |
| H_06_02 | If record is only present in File, then delete from File | (1). File pointers (2). Id | SUCCESS | SUCCESS | Technical |
| H_06_03 | If record is deleted, then Index from Index File should also be deleted | (1). File pointers (2). Id | SUCCESS | SUCCESS | Technical |
| H_07 | When required list can be stored in file | (1). File pointers (2). Head Pointer (3). Flag| SUCCESS | SUCCESS | Requirement based |
| H_08 | When program shuts down records should be saved in File | (1). File pointers (2). Head Pointer| SUCCESS | SUCCESS | Requirement based |
| H_08_01 | When program Shuts down all allocated Memory Locations should be freed | (1). Head Pointer| No Memory Leaks | **FAIL** | Technical |
