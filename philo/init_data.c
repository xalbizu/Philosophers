/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:39:32 by xalbizu-          #+#    #+#             */
/*   Updated: 2023/03/28 21:50:17 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void	init_data(t_data *data, char *argv[])
{
	data->num_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->num_times_eat = ft_atoi(argv[5]);
	else
		data->num_times_eat = -1;
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

	pthread_mutex_init(&data->philosophers[0].print, NULL);
	pthread_mutex_init(&data->philosophers[0].death, NULL);
	i = -1;
	while (++i < data->num_philosophers)
	{
		data->philosophers[i].id = i;
		data->philosophers[i].num_meals = 0;
		pthread_mutex_init(&data->philosophers[i].r_fork, NULL);
		if (i > 0)
		{
			data->philosophers[i].l_fork = data->philosophers[i - 1].r_fork;
			data->philosophers[i].print = data->philosophers[0].print;
			data->philosophers[i].death = data->philosophers[0].death;
		}
		data->philosophers[i].prueba = 0;
	}
	data->philosophers[0].l_fork = data->philosophers[i - 1].r_fork;
	i = -1;
	while (++i < data->num_philosophers)
		pthread_create(&data->philosophers[i].thread,
			NULL, (void *)philo_thread, &data->philosophers[i]);
}
