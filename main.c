#include "philo.h"

int main(int ac, char **av)
{
    t_data *data;

    data = (t_data *) malloc(sizeof(t_data));
    if (!data || ac > 6 || ac < 5 || !ft_check_args(ac, av))
        ft_error();
    
}