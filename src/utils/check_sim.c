/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sim.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 15:58:25 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/21 16:51:12 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_meals(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_amount)
	{
		if (data->philos->meals_eaten < data->meal_amount)
			return ;
		i++;
	}
	data->sim_active = false;
}

static void	check_death(t_data *data)
{
	size_t	i;
	long	current;

	i = 0;
	current = gettime();
	while (i < data->philo_amount)
	{
		if (current - data->philos->time_eaten > data->time_to_die)
		{
			data->sim_active = false;
			print_action(data, data->philos, DIED);
		}
		i++;
	}
}

void	check_sim(t_data *data)
{
	while (data->sim_active)
	{
		if (data->meals)
			check_meals(data);
		check_death(data);
		usleep(10);
	}
}
