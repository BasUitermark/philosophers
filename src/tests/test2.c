#include "philo.h"

static void	*run_job(void *arg)
{
	t_var	*var;

	var = (t_var *)arg;
	pthread_mutex_lock(&var->lock);
	var->counter += 1;
	printf("Job %d started\n", var->counter);
	sleep(5);
	printf("Job %d finished\n", var->counter);
	pthread_mutex_unlock(&var->lock);

}

int	main(void)
{
	int		i;
	int		err;
	t_var	var;

	var.counter = 0;
	i = 0;
	if (pthread_mutex_init(&var.lock, NULL))
	{
		printf("Mutex init failed!\n");
		exit(EXIT_FAILURE);
	}
	while (i < 2)
	{
		err = pthread_create(&var.tid[i], NULL, &run_job, &var);
		if (err)
			printf("Can't create thread: [%s]\n", strerror(err));
		i++;
	}

	pthread_join(var.tid[0], NULL);
	pthread_join(var.tid[1], NULL);
	pthread_mutex_destroy(&var.lock);
	return 0;
}

// pthread_t tid[2];
// int counter;
// pthread_mutex_t lock;

// void* doSomeThing(void *arg)
// {
// 	pthread_mutex_lock(&lock);

// 	unsigned long i = 0;
// 	counter += 1;
// 	printf("\n Job %d started\n", counter);

// 	for(i=0; i<(0xFFFFFFFF);i++);

// 	printf("\n Job %d finished\n", counter);

// 	pthread_mutex_unlock(&lock);

// 	return NULL;
// }

// int main(void)
// {
// 	int i = 0;
// 	int err;

// 	if (pthread_mutex_init(&lock, NULL) != 0)
// 	{
// 		printf("\n mutex init failed\n");
// 		return 1;
// 	}

// 	while(i < 2)
// 	{
// 		err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
// 		if (err != 0)
// 			printf("\ncan't create thread :[%s]", strerror(err));
// 		i++;
// 	}

// 	pthread_join(tid[0], NULL);
// 	pthread_join(tid[1], NULL);
// 	pthread_mutex_destroy(&lock);

// 	return 0;
// }
