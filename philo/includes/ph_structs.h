#ifndef PH_STRUCTS_H
# define PH_STRUCTS_H

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				tm_each_philosopher_must_eat;
	int				died_philo; // stop

	long long		start_simulation;
	int		simulation_run;

	bool			is_die;
	bool			ready;

	t_philo			*philos;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex; // change the name
	pthread_mutex_t	philo_is_died_mutex; // change table_ready
	pthread_mutex_t	mutex_stop_simlation;
	pthread_mutex_t	stop_flag_mutex; // change stop_simlation_two
	pthread_mutex_t	simulation_run_mutex; // stop_mutex
	pthread_mutex_t	last_meal_mutex; // chang_time
	pthread_mutex_t	check_dead;
	pthread_mutex_t	meals_eaten_mutex;   // inc_meals

}	t_table;

typedef struct s_philo
{
	int				philo_id;
	int				meals_eaten;
	int				right_fork;
	int				left_fork;

	long long		last_meal;

	t_table			*table;
	pthread_t		th;
}	t_philo;

#endif