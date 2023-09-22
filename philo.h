#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
    int       nphilo;
    int       t_die;
    int       t_eat;
    int       t_sleep;
    int       nb_eat;
}           t_data;

typedef struct s_philo
{
    int                   id;
    int                t_eat;
    unsigned long      start;
    unsigned long   last_eat;
    pthread_t          *init;
    pthread_mutex_t    *mute;
    pthread_mutex_t   *print;
    t_data             *data;
}           t_philo;



int	ft_atoi(const char *str);
int	ft_check_args(int ac, char **av);
void	ft_error(void);
int	ft_num(char *str);
pthread_mutex_t	*ft_mutex(t_data data);
int	ft_data(t_data *data, int ac, char **av);
unsigned long	ft_times(void);
t_philo	*ft_handle_philos(t_data data, pthread_mutex_t *forks);
void	ft_check_philos(t_data data, t_philo *philos);
t_philo *ft_pthreads_philos(t_data data, t_philo *philos);
void	*ft_start_routine(void *arg);
void	my_sleep(unsigned long ms_time);
void	ft_eat(t_philo *philo, unsigned long time);
void	ft_sleep(t_philo *philo, unsigned long time);
void	ft_fork(t_philo *philo, unsigned long time);
void	ft_think(t_philo *philo, unsigned long time);

#endif