/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:39:09 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/28 13:26:28 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <memory.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define INTERVAL	100

//========== Colors ============//
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

# define BOLD		"\x1b[1m"
# define ITALIC		"\x1b[3m"
# define LINE		"\x1b[4m"
# define BLINK		"\x1b[5m"
# define CROSS		"\x1b[9m"

/**
 * @brief The enum identifiers for the print function.
 */
typedef enum e_proc
{
	GRABBINGL,
	GRABBINGR,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	FINAL
}	t_proc;

/**
 * @brief The enum identifiers for the cleanup function
 */
typedef enum e_clean
{
	STRUCT,
	DATA,
	PRINT,
	FORKS,
	ALL
}	t_clean;

/**
 * @brief Struct to store gettimeofday data.
 */
typedef struct s_date_time
{
	int	hour;
	int	minutes;
	int	seconds;
	int	msec;
}	t_date_time;

/**
 * @brief The individual philosopher data struct.
 */
typedef struct s_philo
{
	int			id;
	pthread_t	thread;

	long		time_eaten;
	long		meals_eaten;
	void		*left_fork;
	void		*right_fork;
}	t_philo;

/**
 * @brief The program data struct.
 * Stores input arguments, all philosopher structs and the program mutexes.
 */
typedef struct s_data
{
	int				philo_amount;

	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	bool			meals;
	int				meal_amount;

	bool			sim_active;

	t_philo			*philos;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	data_lock;
}	t_data;

/**
 * @brief The wrap struct for thread creation allowing 
 * multiple structs to be imported.
 */
typedef struct s_wrap
{
	t_data	*w_data;
	t_philo	*w_philo;
}	t_wrap;

//======== Setup & Utils functions =========//

/**
 * @brief Checks if the used arguments are of a correct format.
 * 
 * @param argc 
 * @param argv 
 * @return true 
 * @return false 
 */
bool	validate_input(int argc, const char **argv);

/**
 * @brief Initiates the programs data structs based on the 
 * used arguments.
 * 
 * @param data 
 * @param argv 
 * @return true 
 * @return false 
 */
bool	init_data(t_data *data, const char **argv);

/**
 * @brief Cleans all allocated memory and destroys mutexes in
 * case of an error or at the succesfull completion of the program.
 * 
 * @param data 
 * @param n 
 */
void	cleanup(t_data *data, t_clean n);

/**
 * @brief Gets the current time in ms.
 * 
 * @return long 
 */
long	gettime(void);

//======== Simulation functions =========//

/**
 * @brief Executes and starts up multiple threads in 
 * the program with the values that have been setup in the data struct.
 * 
 * @param data 
 * @return true 
 * @return false 
 */
bool	exec_sim(t_data *data);

/**
 * @brief Runs the philosopher life cycle. Run out of pthread_create.
 * 
 * @param arg 
 * @return void* 
 */
void	*philo_sim(void *arg);

/**
 * @brief Checks the simulation every 10ms to check for either a death or for
 * all philosophers to have eaten a set amount (if setup).
 * 
 * @param data 
 */
void	check_sim(t_data *data);

//======== Thread functions =========//

/**
 * @brief Simple boolean to check if the functions returns true or false.
 * 
 * @param thread 
 * @param wrap_data 
 * @return true 
 * @return false 
 */
bool	p_create(pthread_t *thread, t_wrap *wrap_data);

/**
 * @brief Simple boolean to check if the functions returns true or false.
 * 
 * @param mutex 
 * @return true 
 * @return false 
 */
bool	p_mutex_init(pthread_mutex_t *mutex);

/**
 * @brief Simple boolean to check if the functions returns true or false.
 * 
 * @param data 
 */
void	p_join(t_data *data);

/**
 * @brief Simple boolean to check if the functions returns true or false.
 * 
 * @param mutex 
 * @param address 
 * @return true 
 * @return false 
 */
bool	read_data(pthread_mutex_t *mutex, bool *address);

//======== Philo Action functions =========//

/**
 * @brief Locks and unlocks too allow for the holding of forks that are available
 * (unlocked by other threads) and increase specific data values.
 * 
 * @param data 
 * @param philo 
 * @return true 
 * @return false 
 */
bool	philo_eat(t_data *data, t_philo *philo);

/**
 * @brief Sets the philospher to "sleep" for a set amount of time.
 * 
 * @param data 
 * @param philo 
 * @return true 
 * @return false 
 */
bool	philo_sleep(t_data *data, t_philo *philo);

/**
 * @brief Sets the philosopher to wait, "think", 
 * until it can grab available forks.
 * 
 * @param data 
 * @param philo 
 * @return true 
 * @return false 
 */
bool	philo_think(t_data *data, t_philo *philo);

/**
 * @brief Prints the philo_action of the philospher with the current time in ms.
 * 
 * @param data 
 * @param philo 
 * @param proc 
 * @param death 
 */
void	print_action(t_data *data, t_philo *philo, t_proc proc, bool death);

//======== Libft functions ==========//
/* Because 42 just loves to make us copy over libft */
/* instead of letting us include it in the project ¯\_(ツ)_/¯*/
/* Yes I am salty about this c: */

long	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
int		ft_isspace(int c);

#endif
