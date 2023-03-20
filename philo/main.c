/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:00:53 by xalbizu-          #+#    #+#             */
/*   Updated: 2023/03/13 16:40:16 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	struct timeval	start;
	//t_philo			*philosophers;
	//int				num_philosophers;

	gettimeofday(&start, NULL);
	if (argc < 5 || argc > 6)
		return (write(1, "Error: wrong number of arguments\n", 34), 0);
	if (!all_arg_are_int(argv))
		return (0);
	//num_philosophers = ft_atoi(argv[1]);
	//philosophers = malloc(num_philosophers * sizeof(t_philo));
	//if (!philosophers)
		//return (write(1, "Error: unable to allocate memory\n", 34), 0);
	printf("\r%ld\n", elapsed_time(start));
	usleep(1000000);
	printf("\r%ld\n", elapsed_time(start));
}

long int	elapsed_time(struct timeval start)
{
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	return (((actual.tv_sec - start.tv_sec) * 1000)
		+ (actual.tv_usec - start.tv_usec) / 1000);
}
