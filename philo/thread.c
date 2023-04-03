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
	if (philo->id % 2 == 0)
		ft_usleep(100, philo->data);

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
	if (philo->data->dead == 1)
		return ;
	
	pthread_mutex_lock(&philo->data->print);
	write(1, (void *)elapsed_time(philo->data->start_time), 3);
	write(1, &philo->id, 3);
	write(1, &status, 8);
	write(1, "\n", 1);
	pthread_mutex_unlock(&philo->data->print);
}

int check_death(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->num_philosophers)
	{
		
		if (elapsed_time(data->start_time) - data->philosophers[i].last_meal > data->time_to_die)
		{
			pthread_mutex_lock(&data->print);
			printf("%ld %d died\n", elapsed_time(data->start_time), data->philosophers[i].id);
			data->dead = 1;
			return (1);
		}
	}
	return (0);
}

int check_meals(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->num_philosophers)
	{
		if (data->philosophers[i].num_meals < data->num_times_eat)
			return (0);
	}
	printf("All philosophers have eaten %d times\n", data->num_times_eat);
	pthread_mutex_lock(&data->print);
	data->dead = 1;
	exit(0);
	return (1);
}