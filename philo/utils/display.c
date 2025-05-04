#include "../includes/philo.h"

void	display(long long time, int id, const char *action)
{
	printf(CYAN "%lld\t%d\t%s\n\n" RESET, time, id, action);
}
