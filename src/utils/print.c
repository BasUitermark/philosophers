/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 11:31:30 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/23 17:19:10 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <locale.h>

void	print_input(t_data data)
{
	printf("Philo's:	[%d]\n", data.philo_amount);
	printf("Time to die:	[%ldms]\n", data.time_to_die);
	printf("Time to eat:	[%ldms]\n", data.time_to_eat);
	printf("Time to sleep:	[%ldms]\n", data.time_to_sleep);
	if (data.meal_amount > 0)
		printf("Meal amount:	[%d]\n", data.meal_amount);
}

bool	print_action(t_data *data, t_philo *philo, t_process process)
{
	if (!p_mutex_lock(&data->print_lock))
		return (false);
    setlocale(LC_NUMERIC, "");
	printf(BOLD"%'lu [#%d]: "RESET, gettime(), philo->id);
	if (process == GRABBING)
		printf(YELLOW"is grabbing a fork\n"RESET);
	else if (process == EATING)
		printf(GREEN"is eating\n"RESET);
	else if (process == SLEEPING)
		printf(BLUE"is sleeping\n"RESET);
	else if (process == THINKING)
		printf(CYAN"is thinking\n"RESET);
	else if (process == DIED)
		printf(RED"has died\n"RESET);
	if (!p_mutex_unlock(&data->print_lock))
		return (false);
	return (true);
}
