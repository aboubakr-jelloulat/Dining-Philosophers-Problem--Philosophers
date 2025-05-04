#ifndef PH_PROTOTYPE_H
# define PH_PROTOTYPE_H

# include "philo.h"
# include "ph_structs.h"


int	putstr_fd2(const char *str_err);
int	ft_atoi(const char *str);
void	display(long long time, int id, const char *action);
void	ft_usleep(int time, t_philo *philo);

void	init_philosophers(int ac, char *av[]);
int	parse_arguments_and_check(int ac, char **av, t_table *table);

long long	time_since_creation(t_table *table);
long long	this_time(void);


void	solo_philo(t_table *table);


int	get_is_simulation_stopped(pthread_mutex_t *mutex, int *flag);


#endif