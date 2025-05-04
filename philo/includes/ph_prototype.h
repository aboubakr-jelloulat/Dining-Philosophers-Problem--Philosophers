#ifndef PH_PROTOTYPE_H
# define PH_PROTOTYPE_H

# include "philo.h"
# include "ph_structs.h"


int	putstr_fd2(const char *str_err);
int	ft_atoi(const char *str);

void	init_philosophers(int ac, char *av[]);
int	parse_arguments_and_check(int ac, char **av, t_table *table);

long long	time_since_creation(t_philo *philo);
long long	this_time(void);


#endif