/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:23:37 by ajelloul          #+#    #+#             */
/*   Updated: 2025/05/05 20:23:38 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
	display(philo, MSG_FORK);
	display(philo, MSG_FORK);
	display(philo, MSG_EAT);
	ft_usleep(philo->table->time_to_eat, philo);
	pthread_mutex_lock(&philo->table->last_meal_mutex);
	philo->last_meal = this_time();
	pthread_mutex_unlock(&philo->table->last_meal_mutex);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->table->meals_eaten_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->meals_eaten_mutex);
}

void	sleep_and_think(t_philo *philo)
{
	display(philo, MSG_SLEEP);
	ft_usleep(philo->table->time_to_sleep, philo);
	display(philo, MSG_THINK);
}
