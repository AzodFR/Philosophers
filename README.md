# Philosophers

## Philo_one

### Rules

* Usage of mutex
* 1 fork between each philo
* 1 philo = 1 thread

### Method

The philosophers always take their left fork before the right, but at the creation, we create the left fork.
Like this, the last philosopher's left fork is the fork 0 (by making (N + 1) % N_MAX)

## Philo_two

### Rules

* Usage of semaphore
* Each fork are at the center of the table
* 1 philo = 1 thread

### Method

Using semaphore to remake mutex for blocking multiple write, and all forks are in a mutex

## Philo_three

### Rules

* Usage of semaphore
* Each fork are at the center of the table
* 1 philo = 1 process
* Main process != philo

### Method

The life checker is not in the main process anymore, but we fork() each philo to make multi process
and the life checker is in a multi thread inside those forks. Still usign semaphore, the main process 
check the exit status (the state and the number), to check if a philo died (exit 1) or if each philo
eated as much as they can (exit 0 * N_MAX ?)

## Final Grade

![aa](https://camo.githubusercontent.com/1890d425e2dbb090d4d27f285589f3dd4273e3a71600a28173c180efe0ca8e2b/68747470733a2f2f696d6167652e70726e747363722e636f6d2f696d6167652f2d5536727732586352417973505364556b32754768512e706e67)
