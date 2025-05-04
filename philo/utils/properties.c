#include "../includes/philo.h"

int	get_value(pthread_mutex_t *mutex, int *flag)
{
	int	value;

	pthread_mutex_lock(mutex);
	value = *flag;
	pthread_mutex_unlock(mutex);
	return (value);
}

void	set_value(pthread_mutex_t *mutex, int *item, int value)
{
	pthread_mutex_lock(mutex);
	*item = value;
	pthread_mutex_unlock(mutex);
}
