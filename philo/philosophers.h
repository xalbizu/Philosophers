/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:45:39 by xalbizu-          #+#    #+#             */
/*   Updated: 2023/03/13 16:40:20 by xalbizu-         ###   ########.fr       */
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
	int				left_fork;
	int				right_fork;
	int				num_meals;
	pthread_mutex_t	*forks;
	pthread_t		thread;
}					t_philo;
typedef struct s_data
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_eat;
	struct timeval	start_time;
	pthread_mutex_t	mutex;
	t_philo			*philosophers;
}					t_data;
int			all_arg_are_int(char *argv[]);
long int	elapsed_time(struct timeval start);
long int	ft_atoi(const char *str);
#endif
