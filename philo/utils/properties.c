#include "../includes/philo.h"


int	get_is_simulation_stopped(pthread_mutex_t *mutex, int *flag)
{
	int	value;

	pthread_mutex_lock(mutex);
	value = *flag;
	pthread_mutex_unlock(mutex);
	return (value);
}
