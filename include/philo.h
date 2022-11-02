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

typedef struct s_data
{
	long			philo_amount;

	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meal_amount;

	long			start_time;

	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	eat_lock;

	long			timestamp_eaten;
	long			meals_eaten;
}	t_philo;

typedef enum e_process
{
	EATING,
	SLEEPING,
	THINKING,
}	t_process;

//======== Utils =========//

bool	validate_input(int argc, const char **argv);
long	gettime(void);

//======== Libft functions ==========//
/* Because 42 just loves to make us copy over libft */
/* instead of letting us include it in the project ¯\_(ツ)_/¯*/
/* Yes I am salty about this :) */

long	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);

#endif
