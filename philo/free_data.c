/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier <xavier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:04:49 by xavier            #+#    #+#             */
/*   Updated: 2023/04/11 18:40:45 by xavier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void free_data(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->num_philosophers)
    {
        pthread_mutex_destroy(&data->philosophers[i].r_fork);
    }
    pthread_mutex_destroy(&data->print);
    pthread_mutex_destroy(&data->death);
    free(data->philosophers);
}