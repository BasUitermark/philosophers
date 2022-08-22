/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/16 20:39:47 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/19 20:50:34 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec) * 1000) + ((time.tv_usec) / 1000));
}

void *myThreadFun(void *vargp)
{
	sleep(1);
	printf("Printing GeeksQuiz from Thread \n");
	printf("%ld\n", ft_time());
	return NULL;
}

void	thread_test()
{
	pthread_t thread_id;
	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
}


int	main(int argc, char const *argv[])
{
	thread_test();
	return 0;
}
