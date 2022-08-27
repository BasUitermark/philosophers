/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/27 23:41:01 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/27 23:45:18 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	validate_input(int argc, const char **argv)
{
	if (argc != 6)
		return (FALSE);
	return (TRUE);
}