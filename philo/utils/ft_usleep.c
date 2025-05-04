#include "../includes/philo.h"

void	ft_usleep(int required_tm, t_philo *philo)
{
	long long	start_tm;

	start_tm = this_time();
	while ((this_time() - start_tm) < required_tm)
	{
		if (get_is_simulation_stopped(&philo->table->stop_flag_mutex,
				&philo->table->stop_simulation))
			break ;
		usleep (500);
	}
}
