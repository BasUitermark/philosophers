/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 12:09:29 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/21 14:03:44 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_join(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_amount)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

bool	p_mutix_init(pthread_mutex_t *mutex)
{
	if (!mutex || (pthread_mutex_init(mutex, NULL) != 0))
		return (false);
	return (true);
}

bool	p_create(pthread_t *thread, t_wrap *wrap_data)
{
	if (pthread_create(thread, NULL, philo_sim, (void *)wrap_data) != 0)
		return (false);
	return (true);
}

bool	p_mutex_lock(pthread_mutex_t *mutex)
{
	if (!mutex || pthread_mutex_lock(mutex) != 0)
		return (false);
	return (true);
}

bool	p_mutex_unlock(pthread_mutex_t *mutex)
{
	if (!mutex || pthread_mutex_unlock(mutex) != 0)
		return (false);
	return (true);
}
