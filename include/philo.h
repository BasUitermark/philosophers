/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:39:09 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/02 16:30:28 by buiterma      ########   odam.nl         */
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

typedef struct s_data
{
	int	philo_amount;

	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	meal_amount;
}	t_data;

typedef struct s_var
{
	int				counter;
	pthread_mutex_t	lock;
	pthread_t		tid[2];
}	t_var;

typedef struct s_philo
{
	int		id;
	long	timestamp_eaten;
	long	meals_eaten;
}	t_philo;

long	time(void);

//======= libft functions ========//

size_t	ft_putendl_fd(char *str, int fd);
long	ft_atoi(const char *str);

#endif
