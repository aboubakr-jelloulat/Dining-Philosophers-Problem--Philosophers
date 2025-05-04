#include "../includes/philo.h"

long long	this_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

long long	time_since_creation(t_philo *philo)
{
	return (this_time() - philo->table->start_simulation);
}
