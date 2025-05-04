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

	long long		start_simulation;
	long long		simulation_run;
	long long		stop_simulation;

	bool			is_die;
	bool			ready;

	t_philo			*philos;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	table_ready;
	pthread_mutex_t	stop_simlation;
	pthread_mutex_t	stop_simlation_two;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	chang_time;
	pthread_mutex_t	check_dead;
	pthread_mutex_t	inc_meals;

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