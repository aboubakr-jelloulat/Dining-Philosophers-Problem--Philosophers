/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:51:22 by ajelloul          #+#    #+#             */
/*   Updated: 2025/05/04 21:51:23 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_PROTOTYPE_H
# define PH_PROTOTYPE_H

# include "philo.h"
# include "ph_structs.h"

/* 	UTILS  	*/
int			putstr_fd2(const char *str_err);
int			ft_atoi(const char *str);
void		display(t_philo *philo, const char *action);
void		ft_usleep(int time, t_philo *philo);

/*	INIT BADY	*/
void		init_philosophers(int ac, char *av[]);
void		dining_philos_problem(t_table *table);
void		solo_philo(t_table *table);
int			parse_arguments_and_check(int ac, char **av, t_table *table);

/*	SYSTEM TIME		*/
long long	time_since_creation(t_table *table);
long long	this_time(void);

/*	PROPERTIES	*/
int			get_value(pthread_mutex_t *mutex, int *flag);
void		set_value(pthread_mutex_t *mutex, int *item, int value);

/*	PHILOS ACTIONS	*/
void		eating(t_philo *philo);
void		sleep_and_think(t_philo *philo);

#endif