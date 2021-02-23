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

##Philo_three

### Rules

* Usage of semaphore
* Each fork are at the center of the table
* 1 philo = 1 process
* Main process != philo