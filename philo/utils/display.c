/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:56:28 by ajelloul          #+#    #+#             */
/*   Updated: 2025/05/05 19:56:31 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	display(t_philo *philo, const char *action)
{
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
