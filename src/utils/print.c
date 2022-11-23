/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 11:31:30 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/23 18:46:39 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <locale.h>
#include <time.h>
#include <sys/time.h>

typedef struct DateAndTime
{
	int	hour;
	int	minutes;
	int	seconds;
	int	msec;
}	t_DateAndTime;

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
	t_DateAndTime	date_and_time;
	struct timeval	tv;
	struct tm		*tm;

	gettimeofday(&tv, NULL);
	tm = localtime(&tv.tv_sec);
	date_and_time.hour = tm->tm_hour;
	date_and_time.minutes = tm->tm_min;
	date_and_time.seconds = tm->tm_sec;
	date_and_time.msec = (int)(tv.tv_usec / 1000);
	if (!p_mutex_lock(&data->print_lock))
		return (false);
	printf(BOLD"%02d:%02d:%02d.%03d \x1b[34m[philo #%d]:	"RESET,
		date_and_time.hour,
		date_and_time.minutes,
		date_and_time.seconds,
		date_and_time.msec,
		philo->id);
	// printf(BOLD"%'lu [#%d]: "RESET, gettime(), philo->id);
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
