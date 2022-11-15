/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 11:31:30 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/14 13:28:41 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_input(t_data data)
{
	printf("Philo's:	[%d]\n", data.philo_amount);
	printf("Time to die:	[%ldms]\n", data.time_to_die);
	printf("Time to eat:	[%ldms]\n", data.time_to_eat);
	printf("Time to sleep:	[%ldms]\n", data.time_to_sleep);
	if (data.meal_amount > 0)
		printf("Meal amount:	[%d]\n", data.meal_amount);
}
