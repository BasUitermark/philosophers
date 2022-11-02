/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:53:12 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/02 16:20:14 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_data(t_data *data, const char **argv)
{
	data->philo_amount = malloc(argv[1]);
	data->time_to_die = malloc(argv[2]);
	data->time_to_eat = malloc(argv[3]);
	data->time_to_sleep = malloc(argv[4]);
	data->meal_amount = malloc(argv[5]);
}
