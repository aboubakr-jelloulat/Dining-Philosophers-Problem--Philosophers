#include "../includes/philo.h"

void	display(t_philo *philo, const char *action)
{
	/* Use philo_is_died_mutex consistently for died_philo */
	pthread_mutex_lock(&philo->table->philo_is_died_mutex);
	if (!philo->table->died_philo)
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf(CYAN "%lld\t%d\t%s\n\n" RESET, time_since_creation(philo->table),
			philo->philo_id, action);
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	pthread_mutex_unlock(&philo->table->philo_is_died_mutex);
}