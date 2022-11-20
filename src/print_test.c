/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/20 16:20:41 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/20 16:32:56 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <string.h>

int	main(int argc, char const *argv[])
{
	char	*color;
	char	*type;

	color = strdup(RED);
	printf("%s%shello world\n", RED, BOLD);
	printf("wut\n");
}
