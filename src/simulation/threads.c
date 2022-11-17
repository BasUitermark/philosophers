/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 12:09:29 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/17 17:05:58 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	p_create(pthread_t thread, t_wrap *wrap_data)
{
	if (pthread_create(&thread, NULL, philo_sim, (void *)wrap_data) != 0)
		return (false);
	return (true);
}

bool	start_threads(t_data data)
{
	int		i;
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
			return (false);
		i++;
	}
	return (true);
}
