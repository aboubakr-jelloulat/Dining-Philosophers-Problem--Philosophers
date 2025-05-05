/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_philo_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:04:57 by ajelloul          #+#    #+#             */
/*   Updated: 2025/05/05 20:06:01 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
 *
 * solo_death_lifecycle
 * 
 * Handles the edge case of a single philosopher who can only grab
 * one fork and will inevitably die after time_to_die elapses.
 * This function simulates the entire lifecycle: fork acquisition,
 * waiting for death, and reporting death.
 * 
 * @param args Pointer to the table data structure
 * @return NULL when execution completes
*/

void	*solo_death_lifecycle(void *args)
{
	t_table	*table;

	table = (t_table *)args;
	table->start_simulation = this_time();
	printf(CYAN "%lld\t%d\t%s\n\n" RESET, time_since_creation(table), 1, MSG_FORK);
	ft_usleep(table->time_to_die, table->philos);
	printf(CYAN "%lld\t%d\t%s\n\n" RESET, time_since_creation(table), 1, MSG_DIED);
	return (NULL);
}

void	solo_philo(t_table *table)
{
	pthread_create(&table->philos[0].th, NULL, solo_death_lifecycle, table);
}
