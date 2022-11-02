/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/09 18:51:20 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/20 21:33:57 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(const char *str)
{
	long	i;
	long	min;
	long	out;

	i = 0;
	min = 1;
	out = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		out = out * 10 + (str[i] - '0');
		i++;
	}
	return (out * min);
}
