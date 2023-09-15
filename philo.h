#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
    int                 nphilo;
    pthread_mutex_t		*forks;
    pthread_mutex_t		*data_race;
    pthread_mutex_t     aff;
    unsigned long       t_die;
    unsigned long       t_eat;
    unsigned long       t_sleep;
    unsigned long	    current_time;
    int                 nb_time_philo_eat;
}           t_data;


int	ft_atoi(const char *str);
int	ft_check_args(int ac, char **av);
void	ft_error(void);
int	ft_num(char *str);

#endif