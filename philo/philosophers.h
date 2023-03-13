/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:45:39 by xalbizu-          #+#    #+#             */
/*   Updated: 2023/03/13 15:57:14 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				num_meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex;
	pthread_t		thread;
}					t_philo;
int			all_arg_are_int(char *argv[]);
long int	elapsed_time(struct timeval start);
#endif
