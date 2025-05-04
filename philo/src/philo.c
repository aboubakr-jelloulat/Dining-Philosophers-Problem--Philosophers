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
}
