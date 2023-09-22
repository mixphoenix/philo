#include "../philo.h"

void	ft_error(void)
{
	printf("invalid args\n");
	exit(0);
}

int	ft_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long	i;
	unsigned long	res;
	int	s;

	i = 0;
	s = 1;
	res = 0;
	while ((str[i] == '\n') || (str[i] == ' ') || (str[i] == '\t')
		|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			s = -1;
		else
			s = 1;
		i++;
	}
	if ((str[i] == '-') || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9' && (str[i] != '\0'))
		res = res * 10 + str[i++] - '0';
	return (res * s);
}

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
