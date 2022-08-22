/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 10:27:51 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/22 10:33:53 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec) * 1000) + ((time.tv_usec) / 1000));
}
