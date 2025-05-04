#include "../includes/philo.h"

static	void	*routine(void	*args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->philo_id % 2 == 0)
			ft_usleep(philo->table->time_to_eat / 2, philo);
	while (true)
	{
		if (get_value(&philo->table->philo_is_died_mutex, &philo->table->died_philo))
			break ;
		if (!get_value(&philo->table->simulation_run_mutex, &philo->table->simulation_run))
			break ;
		eating(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}

static void	meals_required(t_table *table)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < table->num_philosophers)
	{
		if (table->philos[i].meals_eaten >= table->tm_each_philosopher_must_eat)
			cnt++;
		i++;
	}
	if (cnt == table->num_philosophers)
	{
		set_value(&table->philo_is_died_mutex, &table->died_philo, 1);
		set_value(&table->stop_flag_mutex, &table->simulation_run, 0);
	}
}

static void	lmonitor_ya_lmonitor(t_table *table)
{
	int i;

	while (table->simulation_run)
	{
		i = 0;
		while (i < table->num_philosophers)
		{
			if (this_time() - table->philos[i].last_meal >= table->time_to_die)
			{
				set_value(&table->philo_is_died_mutex, &table->died_philo, 1);
				set_value(&table->stop_flag_mutex, &table->simulation_run, 0);
				pthread_mutex_lock(&table->print_mutex);
				printf(CYAN "%lld\t%d\t%s\n\n" RESET, time_since_creation(table), 1, MSG_DIED);
				break ;
			}
			i++;
		}
		if (!get_value(&table->simulation_run_mutex, &table->simulation_run))
			return ;
		if (table->tm_each_philosopher_must_eat != -42)
			meals_required(table);
	}
}

void	dining_philos_problem(t_table *table)
{
	int	u;

	u = 0;
	table->died_philo = 0;
	table->start_simulation = this_time();
	while (u < table->num_philosophers)
	{
		pthread_create(&table->philos[u].th, NULL, routine, &table->philos[u]);
		u++;
	}
	lmonitor_ya_lmonitor(table);
}
