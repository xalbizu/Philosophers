/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:18:14 by xalbizu-          #+#    #+#             */
/*   Updated: 2023/03/29 17:26:13 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void	*philo_thread(t_philo *philo)
{

	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->r_fork);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		ft_usleep(philo->data->time_to_eat * 1000, philo->data);
		philo->num_meals++;
		philo->last_meal = elapsed_time(philo->data->start_time);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(&philo->r_fork);
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep * 1000, philo->data);
		print_status(philo, "is thinking");
	}
	return (NULL);
}

void	ft_usleep(int time, t_data *data)
{
	long int		start_time;
	
	start_time = elapsed_time(data->start_time);
	while ((elapsed_time(data->start_time)) - start_time < time / 1000)
	{
		//printf("elapsed time: %ld , %d\n", elapsed_time(data->start_time) - start_time, time);
		usleep(100);
	}
		
}

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s\n", elapsed_time(philo->data->start_time), philo->id, status);
	pthread_mutex_unlock(&philo->data->print);
}

void check_death(t_philo *philo)
{
	if (elapsed_time(philo->data->start_time) - philo->last_meal > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%ld %d died", elapsed_time(philo->data->start_time), philo->id);
		pthread_mutex_unlock(&philo->data->print);
		philo->data->dead = 1;
		return ;
	}
}

