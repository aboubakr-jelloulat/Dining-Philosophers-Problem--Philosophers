#include "../includes/philo.h"

void	ft_usleep(int required_tm, t_philo *philo)
{
	long long	start_tm;
	int		died;

	start_tm = this_time();
	while ((this_time() - start_tm) < required_tm)
	{
		/* Lock the mutex before reading died_philo */
		pthread_mutex_lock(&philo->table->philo_is_died_mutex);
		died = philo->table->died_philo;
		pthread_mutex_unlock(&philo->table->philo_is_died_mutex);
	
		if (died)
			break;
		usleep(500);
	}
}
