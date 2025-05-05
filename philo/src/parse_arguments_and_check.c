/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments_and_check.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:01:46 by ajelloul          #+#    #+#             */
/*   Updated: 2025/05/05 20:01:53 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_valid_argument(int ac, t_table *table)
{
	if (table->num_philosophers <= 0)
		return (putstr_fd2(ERR_NUM_PHILOS));
	if (table->time_to_die <= 0)
		return (putstr_fd2(ERR_TIME_TO_DIE));
	if (table->time_to_eat <= 0)
		return (putstr_fd2(ERR_TIME_TO_EAT));
	if (table->time_to_sleep <= 0)
		return (putstr_fd2(ERR_TIME_TO_SLEEP));
	if (ac == 6 && table->tm_each_philosopher_must_eat < 0)
		return (putstr_fd2(ERR_TIMES_MUST_EAT));
	return (0);
}

int	parse_arguments_and_check(int ac, char **av, t_table *table)
{
	table->num_philosophers = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->tm_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		table->tm_each_philosopher_must_eat = -42;
	return (is_valid_argument(ac, table));
}
