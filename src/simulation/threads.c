/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 12:09:29 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/24 19:07:07 by buiterma      ########   odam.nl         */
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

bool	read_data(pthread_mutex_t *mutex, bool *address)
{
	bool	result;

	pthread_mutex_lock(mutex);
	result = *address;
	pthread_mutex_unlock(mutex);
	return (result);
}
