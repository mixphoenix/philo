#include "philo.h"

int main(int ac, char **av)
{
    t_data *data;
    t_philo *philos;
    pthread_mutex_t *forks;

    data = (t_data *) malloc(sizeof(t_data));
    if (!data || ac > 6 || ac < 5 || !ft_check_args(ac, av))
        ft_error();
    if (!ft_data(data, ac, av))
		ft_error();
    forks = ft_mutex(*data);
    philos = ft_handle_philos(*data, forks);
    ft_check_philos(*data, philos);
}