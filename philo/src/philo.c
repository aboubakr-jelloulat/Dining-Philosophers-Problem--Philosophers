/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:00:03 by ajelloul          #+#    #+#             */
/*   Updated: 2025/05/05 20:00:04 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	usage(void)
{
	return (putstr_fd2("\nError : Invalid arguments\n\n"
			"Usage: ./philo  <number_of_philos>  <time_to_die> "
			"<time_to_eat> <time_to_sleep>  "
			"[number_of_times_eacih_philosopher_must_eat]\n"));
}

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (usage());
	init_philosophers(ac, av);
	return (0);
}
