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
			break;
		if (!get_value(&philo->table->stop_flag_mutex, &philo->table->simulation_run))
			break;
		eating(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}

static void	meals_required(t_table *table)
{
	int	i;
	int	cnt;
	int	meals;

	i = 0;
	cnt = 0;
	while (i < table->num_philosophers)
	{
		/* Lock the meals_eaten_mutex before reading meals_eaten */
		pthread_mutex_lock(&table->meals_eaten_mutex);
		meals = table->philos[i].meals_eaten;
		pthread_mutex_unlock(&table->meals_eaten_mutex);
		
		if (meals >= table->tm_each_philosopher_must_eat)
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
	int	i;
	int	run_simulation;

	/* Check simulation_run using the correct mutex */
	while (get_value(&table->stop_flag_mutex, &table->simulation_run))
	{
		i = 0;
		while (i < table->num_philosophers)
		{
			pthread_mutex_lock(&table->last_meal_mutex);
			if (this_time() - table->philos[i].last_meal >= table->time_to_die)
			{
				pthread_mutex_unlock(&table->last_meal_mutex);
				set_value(&table->philo_is_died_mutex, &table->died_philo, 1);
				set_value(&table->stop_flag_mutex, &table->simulation_run, 0);
				pthread_mutex_lock(&table->print_mutex);
				printf(CYAN "%lld\t%d\t%s\n\n" RESET, 
					time_since_creation(table), i + 1, MSG_DIED);
				//pthread_mutex_unlock(&table->print_mutex);
				return;
			}
			pthread_mutex_unlock(&table->last_meal_mutex);
			i++;
		}
		/* Use the correct mutex for simulation_run */
		run_simulation = get_value(&table->stop_flag_mutex, &table->simulation_run);
		if (!run_simulation)
			return ;
		if (table->tm_each_philosopher_must_eat != -42)
			meals_required(table);
	}
}

static void	*monitor_routine(void *args)
{
	t_table	*table;

	table = (t_table *)args;
	lmonitor_ya_lmonitor(table);
	return (NULL);
}

void	dining_philos_problem(t_table *table)
{
	int			u;
	pthread_t	monitor_thread;

	u = 0;
	table->died_philo = 0;
	table->start_simulation = this_time();
	while (u < table->num_philosophers)
	{
		pthread_create(&table->philos[u].th, NULL, routine, &table->philos[u]);
		u++;
	}
	/* Create a separate monitor thread instead of running in main thread */
	pthread_create(&monitor_thread, NULL, monitor_routine, table);
	pthread_detach(monitor_thread);
}
