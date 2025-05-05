/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:59:16 by ajelloul          #+#    #+#             */
/*   Updated: 2025/05/05 19:59:17 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	this_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

long long	time_since_creation(t_table *table)
{
	return (this_time() - table->start_simulation);
}
