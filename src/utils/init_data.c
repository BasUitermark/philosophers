/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 21:58:18 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/28 12:04:42 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	read_args(t_data *data, const char **argv)
{
	data->meal_amount = 0;
	data->meals = false;
	data->philo_amount = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		data->meals = true;
		data->meal_amount = ft_atoi(argv[5]);
	}
	return (true);
}

static bool	init_philo(t_data *data)
{
	size_t	i;

	i = 0;
	data->philos = ft_calloc(data->philo_amount, sizeof(t_philo));
	if (!data->philos)
		return (false);
	data->fork = ft_calloc(data->philo_amount, sizeof(pthread_mutex_t));
	if (!data->fork)
	{
		free (data->philos);
		return (false);
	}
	while (i < data->philo_amount)
	{
		if (!p_mutex_init(&data->fork[i]))
		{
			free (data->philos);
			free (data->fork);
			return (false);
		}
		if (data->meals)
			data->philos[i].meals_eaten = 0;
		i++;
	}
	return (true);
}

static void	attach_forks(t_data *data)
{
	size_t	i;

	i = 0;
	data->philos[i].right_fork = &data->fork[data->philo_amount - 1];
	while (i < data->philo_amount)
	{
		data->philos[i].left_fork = &data->fork[i];
		if (i)
			data->philos[i].right_fork = &data->fork[i - 1];
		i++;
	}
}

bool	init_data(t_data *data, const char **argv)
{
	if (!read_args(data, argv))
		return (false);
	if (!init_philo(data))
		return (false);
	if (!p_mutex_init(&data->data_lock))
	{
		cleanup(data, DATA);
		return (false);
	}
	if (!p_mutex_init(&data->print_lock))
	{
		cleanup(data, PRINT);
		return (false);
	}
	attach_forks(data);
	return (true);
}
