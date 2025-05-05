/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:58:27 by ajelloul          #+#    #+#             */
/*   Updated: 2025/05/05 19:58:28 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_usleep(int required_tm, t_philo *philo)
{
	long long	start_tm;
	int			died;

	start_tm = this_time();
	while ((this_time() - start_tm) < required_tm)
	{
		pthread_mutex_lock(&philo->table->philo_is_died_mutex);
		died = philo->table->died_philo;
		pthread_mutex_unlock(&philo->table->philo_is_died_mutex);
		if (died)
			break ;
		usleep(500);
	}
}
