#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <memory.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_data
{
	int	philo_amount;

	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	meal_amount;
}	t_data;
typedef struct	s_var
{
	int	counter;
	pthread_mutex_t	lock;
	pthread_t	tid[2];
}	t_var;

typedef struct	s_philo
{
	int		id;
	long	timestamp_eaten;
	long	meals_eaten;
}	t_philo;

long	time(void);

#endif
