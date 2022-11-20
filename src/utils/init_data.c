/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 21:58:18 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/20 14:37:35 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	read_args(t_data *data, const char **argv)
{
	data->start_time = gettime();
	data->philo_amount = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		data->meals = true;
		data->meal_amount = ft_atoi(argv[5]);
	}
	data->meals = false;
	data->start_time = gettime();
	return (true);
}

static bool	init_philo(t_data *data)
{
	size_t	i;

	i = 0;
	data->philos = ft_calloc(data->philo_amount, sizeof(t_philo));
	if (!data->philos)
		return (false);
	data->fork = ft_calloc(data->philo_amount, sizeof(t_forks));
	if (!data->fork)
	{
		free (data->philos);
		return (false);
	}
	while (i < data->philo_amount)
	{
		data->philos->id = i + 1;
		data->philos->time_eaten = gettime();
		if (!p_mutix_init(&data->fork[i].mutex))
		{
			free (data->philos);
			free (data->fork);
			return (false);
		}
		i++;
	}
	return (true);
}

static void	attach_forks(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_amount)
	{
		if (i == 0)
		{
			data->philos[i].right_fork = data->fork[data->philo_amount - 1];
			data->philos->left_fork = data->fork[i];
		}
		if (i != 0)
		{
			data->philos->right_fork = data->fork[i - 1];
			data->philos->left_fork = data->fork[i];
		}
		i++;
	}
}

bool	init_data(t_data *data, const char **argv)
{
	if (!read_args(data, argv))
		return (false);
	if (!init_philo(data))
		return (false);
	attach_forks(data);
	return (true);
}
