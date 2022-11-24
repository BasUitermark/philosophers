/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 11:31:30 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/24 18:56:31 by buiterma      ########   odam.nl         */
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

static int	calc_fork(t_data *data, t_philo *philo, t_proc proc)
{
	if (philo->id == 1 && proc == GRABBINGR)
		return (data->philo_amount);
	if (proc == GRABBINGR)
		return (philo->id - 1);
	if (proc == GRABBINGL)
		return (philo->id);
	return (0);
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
			printf(YELLOW"is grabbing the left fork %d\n"RESET, calc_fork(data, philo, proc));
		else if (proc == GRABBINGR)
			printf(YELLOW"is grabbing the right fork %d\n"RESET, calc_fork(data, philo, proc));
		else if (proc == EATING)
			printf(GREEN"is eating\n\n"RESET);
		else if (proc == SLEEPING)
			printf(BLUE"is sleeping\n"RESET);
		else if (proc == THINKING)
			printf(MAGENTA"is thinking\n"RESET);
		else if (proc == DIED)
			printf(RED"has died\n"RESET);
		else if (proc == FINAL)
			printf(RED"reached final meal %ld/%d\n"RESET, philo->meals_eaten, data->meal_amount);
		pthread_mutex_unlock(&data->print_lock);
	}
}

	// printf(BOLD"%'lu [#%d]: "RESET, gettime(), philo->id);