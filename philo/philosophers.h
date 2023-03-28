/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:45:39 by xalbizu-          #+#    #+#             */
/*   Updated: 2023/03/28 21:55:19 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				num_meals;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_t		thread;
	int 			prueba;
}					t_philo;
typedef struct s_data
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_eat;
	struct timeval	start_time;
	t_philo			*philosophers;
}					t_data;
int			all_arg_are_int(char *argv[]);
long int	elapsed_time(struct timeval start);
long int	ft_atoi(const char *str);
void		init_data(t_data *data, char *argv[]);
void		init_philos(t_data *data);
void		*philo_thread(t_philo *philo);
#endif
