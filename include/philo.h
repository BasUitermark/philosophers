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

typedef struct s_var
{
	int	counter;
	pthread_mutex_t	lock;
	pthread_t	tid[2];
}	t_var;

typedef struct	s_philo
{
	int		id;
	long	timestap_eaten;
}	t_philo;

long	time(void);

#endif
