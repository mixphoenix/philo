#include "../philo.h"

void	ft_think(t_philo *philo, unsigned long time)
{
	pthread_mutex_lock(philo->print);
	printf("%ld philo %d is thinking \n ", time, philo->id + 1);
	pthread_mutex_unlock(philo->print);
}

void	ft_fork(t_philo *philo, unsigned long time)
{
	pthread_mutex_lock(philo->print);
	printf("%ld philo %d took a fork \n ", time, philo->id + 1);
	pthread_mutex_unlock(philo->print);
}

void	ft_eat(t_philo *philo, unsigned long time)
{
	pthread_mutex_lock(philo->print);
	printf("%ld philo %d is eating \n ", time, philo->id + 1);
	pthread_mutex_unlock(philo->print);
	my_sleep(philo->data->t_eat);
	philo->last_eat = ft_times();
}

void	ft_sleep(t_philo *philo, unsigned long time)
{
	pthread_mutex_lock(philo->print);
	printf("%ld philo %d is sleeping \n ", time, philo->id + 1);
	pthread_mutex_unlock(philo->print);
	my_sleep(philo->data->t_sleep);
}
