# Philosophers

## Research about unknown function

`usleep` ==> suspend thread execution (in microsecond) // 0: OK -1: Fail

`gettimeofday` ==> get time from (01/01/1970) // timeval tv_sec & tv_usec // ingore timezone

`pthread_create` ==> Create new thread

`pthread_detach` ==> Marks a thread deletion

`pthread_join` ==> Make a thread wait another

`pthread_mutex_init` ==> Init a mutex with specified attributes

`pthread_mutex_destroy` ==> Destroy a mutex

`pthread_mutex_lock` ==> Lock a mutex and block it until it becomes available

`pthread_mutex_unlock` ==> Unlock a mutex

## Lexical 

`Thread` ==> Independant set of values for the processor register

`Mutex` ==> Prevent a ressource to be used by 2 threads at the same time