/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:39:09 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/17 17:41:22 by buiterma      ########   odam.nl         */
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

typedef enum e_process
{
	EATING,
	SLEEPING,
	THINKING,
}	t_process;

typedef struct s_wrap
{
	t_data	w_data;
	t_philo	w_philo;
}	t_wrap;


typedef struct s_philo
{
	int				id;
	pthread_t		thread;

	long			timestamp_eaten;
	long			meals_eaten;
	t_process		state;
}	t_philo;

typedef struct s_forks
{
	pthread_mutex_t	fork_lock;
	
}	t_forks;

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


//======== Setup & Utils functions =========//

bool	validate_input(int argc, const char **argv);
bool	init_data(t_data *data, const char **argv);
long	gettime(void);

//======== Simulation functions =========//
bool	exec_sim(t_data data);
void	*philo_sim(void *arg);

//======== Thread functions =========//
bool	start_threads(t_data data);

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

//======== Test functions =======//

void	print_input(t_data data);

#endif
