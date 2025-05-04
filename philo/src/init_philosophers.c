#include "../includes/philo.h"

static void	init_mutex(t_table *table)
{
	pthread_mutex_init(&table->stop_mutex, NULL);
	pthread_mutex_init(&table->table_ready, NULL);
	pthread_mutex_init(&table->mutex_print, NULL); // only this is changed
	pthread_mutex_init(&table->mutex_stop_simlation, NULL);
	pthread_mutex_init(&table->stop_simlation_two, NULL);
	pthread_mutex_init(&table->check_dead, NULL);
	pthread_mutex_init(&table->chang_time, NULL);
	pthread_mutex_init(&table->inc_meals, NULL);
}

static int	init_thread_and_mutex(t_table *table)
{
	int	u;

	u = 0;
	table->philos = malloc(sizeof(t_philo) * table->num_philosophers);
	if (!table->philos)
		return (1);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philosophers);
	if (!table->forks)
		return (free(table->philos), 1);
	init_mutex(table);
	table->is_die = false;
	table->simulation_run = 1;
	table->stop_simulation = 0;
	while (u < table->num_philosophers)
	{
		table->philos[u].philo_id = u + 1;
		table->philos[u].last_meal = this_time();
		table->philos[u].table = table;
		table->philos[u].meals_eaten = 0;
		table->philos[u].right_fork = (u + 1) % table->num_philosophers;
		table->philos[u].left_fork = u;
		pthread_mutex_init(&table->forks[u], NULL);
		u++;
	}
	return (0);
}

void	init_philosophers(int ac, char *av[])
{
	t_table	table;

	if (parse_arguments_and_check(ac, av, &table))
		return ;
	if (init_thread_and_mutex(&table))
		return ;
	
}
