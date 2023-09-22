#include "../philo.h"

void	ft_check_philos(t_data data, t_philo *philos)
{
	int	stop;
	int	x;

	while (1)
	{
		x = 0;
		stop = 0;
		while (x < data.nphilo)
		{
			if (philos[x].t_eat == data.nb_eat)
				stop++;
			if ((int )(ft_times() - philos[x].last_eat) >= data.t_die)
			{
				pthread_mutex_lock(philos[x].print);
				printf("%ld philo %d died \n ", ft_times() - philos[x].start,
					philos->id + 1);
				return ;
			}
			x++;
		}
		if (stop == data.nb_eat)
			return ;
	}

}

unsigned long	ft_times(void)
{
	unsigned long	time;
	struct timeval	t;

	gettimeofday(&t, NULL);
	time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	return (time);
}

void	my_sleep(unsigned long ms_time)
{
	unsigned long	t;

	t = ft_times();
	while (ft_times() - t < ms_time)
		usleep(50);
}