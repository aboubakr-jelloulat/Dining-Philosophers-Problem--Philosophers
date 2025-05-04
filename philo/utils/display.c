#include "../includes/philo.h"

void	display(t_philo *philo, const char *action)
{
	pthread_mutex_lock(&philo->table->simulation_run_mutex);
	if (!philo->table->died_philo)
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf(CYAN "%lld\t%d\t%s\n\n" RESET, time_since_creation(philo->table),
			philo->philo_id, action);
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	pthread_mutex_unlock(&philo->table->simulation_run_mutex);
}
