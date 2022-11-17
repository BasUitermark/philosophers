/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 12:08:59 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/17 17:52:11 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_sim(void *arg)
{
	t_data	data;
	t_philo	philo;

	data = ((t_wrap *)arg->w_data);
	philo = ((t_wrap *)arg->w_philo);
	free ()
	while ()
	return (NULL);
}

bool	exec_sim(t_data data)
{
	if (!start_threads(data))
		return (false);
	return (true);
}
