/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:18:14 by xalbizu-          #+#    #+#             */
/*   Updated: 2023/03/28 21:51:34 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void	*philo_thread(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->print);
		printf("philo %d\n", philo->id);
		philo->prueba = 1;
		pthread_mutex_unlock(&philo->print);
		if (philo->prueba == 1)
			return (NULL) ;
	}
}
