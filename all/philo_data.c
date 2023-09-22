#include "../philo.h"

int	ft_data(t_data *data, int ac, char **av)
{
	data->nphilo = atoi(av[1]);
	if (data->nphilo <= 0)
		return (0);
	data->t_die = atoi(av[2]);
	data->t_eat = atoi(av[3]);
	data->t_sleep = atoi(av[4]);
	data->nb_eat = -1;
	if (ac == 6)
		data->nb_eat = atoi(av[5]);
	return (1);
}

pthread_mutex_t	*ft_mutex(t_data data)
{
	pthread_mutex_t	*mutex;
	int				i;

	i = 0;
	mutex = (pthread_mutex_t *)malloc (sizeof(pthread_mutex_t) * data.nphilo);
	while (i < data.nphilo)
	{
		pthread_mutex_init(mutex + i, NULL);
		i++;
	}
	return (mutex);
}

t_philo	*ft_handle_philos(t_data data, pthread_mutex_t *forks)
{
	int				i;
	t_philo			*philos;
	pthread_mutex_t	*is_dead = NULL;
	unsigned long	time;

	i = 0;
	is_dead = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(is_dead, NULL);
	philos = (t_philo *)malloc(sizeof(t_philo) * data.nphilo);
	time = ft_times();
	while (i < data.nphilo)
	{
		philos[i].init = (pthread_t *)malloc(sizeof(pthread_t));
		philos[i].id = i;
		philos[i].mute = forks;
		philos[i].start = time;
		philos[i].t_eat = 0;
		philos[i].last_eat = time;
		philos[i].print = is_dead;
		philos[i].data = &data;
		i++;
	}
    philos = ft_pthreads_philos(data, philos);
    return (philos);
}

t_philo *ft_pthreads_philos(t_data data, t_philo *philos)
{
    int i;

    i = 0;
    while (i < data.nphilo)
	{
		pthread_create(philos->init + i, NULL, &ft_start_routine, &philos[i]);
		i += 2;
	}
	my_sleep(1);
	i = 1;
	while (i < data.nphilo)
	{
		pthread_create(philos->init + i, NULL, &ft_start_routine, &philos[i]);
		i += 2;
	}
	return (philos);
}

void	*ft_start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->mute[philo->id]);
		ft_fork(philo, ft_times() - philo->start);
		pthread_mutex_lock(&philo->mute[(philo->id + 1) % philo->data->nphilo]);
		ft_fork(philo, ft_times() - philo->start);
		ft_eat(philo, ft_times() - philo->start);
		pthread_mutex_unlock(&philo->mute[philo->id]);
		pthread_mutex_unlock(&philo->mute[(philo->id + 1) % philo->data->nphilo]);
		if (philo->data->nb_eat != -1)
			philo->t_eat++;
		if (philo->t_eat == philo->data->nb_eat)
			break ;
		ft_sleep(philo, ft_times() - philo->start);
		ft_think(philo, ft_times() - philo->start);
	}
	return (NULL);
}