/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 12:08:59 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/20 17:26:00 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_sim(void *arg)
{
	t_data	data;
	t_philo	philo;

	data = ((t_wrap *)arg)->w_data;
	philo = ((t_wrap *)arg)->w_philo;
	free ((t_wrap *)arg);
	while (data.sim_active)
	{
		
	}
	return (NULL);
}

static bool	start_threads(t_data data)
{
	size_t	i;
	t_wrap	*wrap_data;

	i = 0;
	while (i < data.philo_amount)
	{
		wrap_data = malloc(sizeof(t_wrap));
		if (!wrap_data)
			return (false);
		data.philos[i].id = i + 1;
		wrap_data->w_data = data;
		wrap_data->w_philo = data.philos[i];
		if (!p_create(data.philos[i].thread, &wrap_data))
		{
			free (wrap_data);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	exec_sim(t_data data)
{
	if (!start_threads(data))
	{
		free (data.philos);
		free (data.fork);
		return (false);
	}
	return (true);
}
