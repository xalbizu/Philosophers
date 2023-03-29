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
	while (1)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("philo %d\n", philo->id);
		pthread_mutex_unlock(&philo->data->print);
		return (NULL);
	}
}
