#include "philo.h"

int	ft_check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) == 0)
			return (0);
		if (!ft_num(av[i]))
			return (0);
		i++;
	}
	return (1);
}
