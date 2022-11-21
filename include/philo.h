/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:39:09 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/21 16:40:24 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

# define BOLD		"\x1b[1m"
# define ITALIC		"\x1b[3m"
# define LINE		"\x1b[4m"
# define BLINK		"\x1b[5m"
# define CROSS		"\x1b[9m"

typedef enum e_process
{
	GRABBING,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_process;

typedef struct s_forks
{
	pthread_mutex_t	mutex;
}	t_forks;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;

	long		time_eaten;
	long		meals_eaten;
	t_process	state;
	t_forks		left_fork;	
	t_forks		right_fork;	
}	t_philo;

typedef struct s_data
{
	int				philo_amount;

	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	bool			meals;
	int				meal_amount;

	long			start_time;
	bool			sim_active;

	t_philo			*philos;
	t_forks			*fork;
	pthread_mutex_t	print_lock;
}	t_data;

typedef struct s_wrap
{
	t_data	*w_data;
	t_philo	*w_philo;
}	t_wrap;

//======== Setup & Utils functions =========//

bool	validate_input(int argc, const char **argv);
bool	init_data(t_data *data, const char **argv);
long	gettime(void);

//======== Simulation functions =========//
bool	exec_sim(t_data *data);
void	*philo_sim(void *arg);
void	check_sim(t_data *data);

//======== Thread functions =========//
bool	p_create(pthread_t *thread, t_wrap *wrap_data);
bool	p_mutix_init(pthread_mutex_t *mutex);
bool	p_mutex_lock(pthread_mutex_t *mutex);
bool	p_mutex_unlock(pthread_mutex_t *mutex);
void	p_join(t_data *data);

//======== Philo Action functions =========//
void	philo_eat(t_data *data, t_philo *philo);
void	philo_sleep(t_data *data, t_philo *philo);
void	philo_think(t_data *data, t_philo *philo);
bool	print_action(t_data *data, t_philo *philo, t_process process);

//======== Libft functions ==========//
/* Because 42 just loves to make us copy over libft */
/* instead of letting us include it in the project ¯\_(ツ)_/¯*/
/* Yes I am salty about this c: */

long	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
int		ft_isspace(int c);

#endif
