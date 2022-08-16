/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/16 20:39:47 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/16 20:45:57 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec) * 1000) + ((time.tv_usec) / 1000));
}

int	main(int argc, char const *argv[])
{
	printf("%ld\n", ft_time());
	return 0;
}
