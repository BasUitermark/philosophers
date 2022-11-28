/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 11:31:30 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/28 12:22:04 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <locale.h>
#include <time.h>
#include <sys/time.h>

void	print_input(t_data data)
{
	printf("Philo's:	[%d]\n", data.philo_amount);
	printf("Time to die:	[%ldms]\n", data.time_to_die);
	printf("Time to eat:	[%ldms]\n", data.time_to_eat);
	printf("Time to sleep:	[%ldms]\n", data.time_to_sleep);
	if (data.meal_amount > 0)
		printf("Meal amount:	[%d]\n", data.meal_amount);
}

static t_date_time	convert_time(void)
{
	t_date_time		date_time;
	struct timeval	tv;
	struct tm		*tm;

	gettimeofday(&tv, NULL);
	tm = localtime(&tv.tv_sec);
	date_time.hour = tm->tm_hour;
	date_time.minutes = tm->tm_min;
	date_time.seconds = tm->tm_sec;
	date_time.msec = (int)(tv.tv_usec / 1000);
	return (date_time);
}

void	print_action(t_data *data, t_philo *philo, t_proc proc, bool death)
{
	t_date_time		dt;

	if (read_data(&data->data_lock, &data->sim_active) || death)
	{
		pthread_mutex_lock(&data->print_lock);
		dt = convert_time();
		printf(BOLD"%02d:%02d:%02d.%03d \x1b[34m[philo #%d]:	"RESET, \
			dt.hour, dt.minutes, dt.seconds, dt.msec, philo->id);
		if (proc == GRABBINGL)
			printf(YELLOW"is grabbing the left fork\n"RESET);
		else if (proc == GRABBINGR)
			printf(YELLOW"is grabbing the right fork\n"RESET);
		else if (proc == EATING)
			printf(GREEN"is eating\n\n"RESET);
		else if (proc == SLEEPING)
			printf(BLUE"is sleeping\n"RESET);
		else if (proc == THINKING)
			printf(MAGENTA"is thinking\n"RESET);
		else if (proc == DIED)
			printf(RED"has died\n"RESET);
		else if (proc == FINAL)
			printf(RED"reached final meal %ld/%d\n"RESET, \
					philo->meals_eaten, data->meal_amount);
		pthread_mutex_unlock(&data->print_lock);
	}
}

	// printf(BOLD"%'lu [#%d]: "RESET, gettime(), philo->id);