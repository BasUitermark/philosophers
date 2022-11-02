/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:36:33 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/02 15:36:48 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_putendl_fd(char *str, int fd)
{
	size_t	out;
	size_t	i;

	out = 0;
	i = 0;
	while (str[i])
	{
		out += write(fd, &str[i], 1);
		i++;
	}
	out += write(fd, "\n", 1);
	return (out);
}
