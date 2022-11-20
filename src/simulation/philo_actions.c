/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 21:37:05 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/20 18:13:51 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_grab_drop(t_data *data, t_philo *philo, bool grab)
{
	if (!data->sim_active)
		return ;
	if (grab)
	{
		p_mutex_lock(&philo->left_fork);
		print_action(data, philo, "grabs fork");
		p_mutex_lock(&philo->right_fork);
		print_action(data, philo, "grabs fork");
	}
	else
	{
		p_mutex_unlock(&philo->left_fork);
		p_mutex_unlock(&philo->right_fork);
	}
}

void	philo_eat(t_data *data, t_philo *philo)
{
	if (!data->sim_active)
		return ;
	philo->state = EATING;
	philo->time_eaten = gettime();
	print_action(data, philo, "is eating");
	set_time_to(data->time_to_eat / 1000);
	philo->time_eaten++;
}

void	philo_sleep(t_data *data, t_philo *philo)
{
	if (!data->sim_active)
		return ;
	philo->state = SLEEPING;
	print_action(data, philo, "is sleeping");
	set_time_to(data->time_to_sleep);
}

void	philo_think(t_data *data, t_philo *philo)
{
	if (!data->sim_active)
		return ;
	philo->state = THINKING;
	print_action(data, philo, "is thinking");
}
