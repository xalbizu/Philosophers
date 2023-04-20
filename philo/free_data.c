/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:04:49 by xavier            #+#    #+#             */
/*   Updated: 2023/04/20 12:31:34 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_data(t_data *data)
{
	int	i;

	unlock_mutex(data);
	i = -1;
	while (++i < data->num_philosophers)
	{
		pthread_mutex_destroy(&data->philosophers[i].r_fork);
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death);
	free(data->philosophers);
}

void	unlock_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philosophers)
	{
		pthread_mutex_unlock(&data->philosophers[i].r_fork);
	}
	ft_usleep(100, data);
	pthread_mutex_unlock(&data->print);
	ft_usleep(1000, data);
}
