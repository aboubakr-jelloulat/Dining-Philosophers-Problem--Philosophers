/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:04:35 by ajelloul          #+#    #+#             */
/*   Updated: 2025/05/05 20:04:36 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	join_and_cleanup(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philosophers)
		pthread_join(table->philos[i++].th, NULL);
	i = 0;
	while (i < table->num_philosophers)
		pthread_mutex_destroy(&table->forks[i++]);
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->stop_flag_mutex);
	pthread_mutex_destroy(&table->mutex_stop_simlation);
	pthread_mutex_destroy(&table->philo_is_died_mutex);
	pthread_mutex_destroy(&table->check_dead);
	pthread_mutex_destroy(&table->last_meal_mutex);
	pthread_mutex_destroy(&table->meals_eaten_mutex);
	pthread_mutex_destroy(&table->simulation_run_mutex);
	free(table->philos);
	table->philos = NULL;
	free(table->forks);
	table->forks = NULL;
}

static void	init_mutex(t_table *table)
{
	pthread_mutex_init(&table->print_mutex, NULL);
	pthread_mutex_init(&table->stop_flag_mutex, NULL);
	pthread_mutex_init(&table->mutex_stop_simlation, NULL);
	pthread_mutex_init(&table->philo_is_died_mutex, NULL);
	pthread_mutex_init(&table->check_dead, NULL);
	pthread_mutex_init(&table->last_meal_mutex, NULL);
	pthread_mutex_init(&table->meals_eaten_mutex, NULL);
	pthread_mutex_init(&table->simulation_run_mutex, NULL);
}

static int	init_data_and_mutex(t_table *table)
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
	table->died_philo = 0;
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
	if (init_data_and_mutex(&table))
		return ;
	if (table.num_philosophers == 1)
		solo_philo(&table);
	else
		dining_philos_problem(&table);
	join_and_cleanup(&table);
}
