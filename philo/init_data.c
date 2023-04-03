/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:39:32 by xalbizu-          #+#    #+#             */
/*   Updated: 2023/03/29 17:15:13 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void	init_data(t_data *data, char *argv[])
{
	data->num_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	printf("time to eat: %d", data->time_to_eat);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->num_times_eat = ft_atoi(argv[5]);
	else
		data->num_times_eat = -1;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->death, NULL);
	gettimeofday(&data->start_time, NULL);
	data->philosophers = malloc(sizeof(t_philo) * data->num_philosophers);
	if (!data->philosophers)
	{
		write(1, "Error: philosophers malloc failed\n", 22);
		return ;
	}
	init_philos(data);
}

void	init_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philosophers)
	{
		data->philosophers[i].id = i;
		data->philosophers[i].num_meals = 0;
		data->dead = 0;
		pthread_mutex_init(&data->philosophers[i].r_fork, NULL);
		if (i > 0)
		{
			data->philosophers[i].l_fork = &data->philosophers[i - 1].r_fork;
		}
		data->philosophers[i].data = data;
	}
	data->philosophers[0].l_fork = &data->philosophers[i - 1].r_fork;
	i = -1;
	while (++i < data->num_philosophers)
	{
		pthread_create(&data->philosophers[i].thread,
			NULL, (void *)philo_thread, &data->philosophers[i]);
	}
	i = -1;
	while (++i < data->num_philosophers)
		pthread_join(data->philosophers[i].thread, NULL);
	
}
