/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:00:53 by xalbizu-          #+#    #+#             */
/*   Updated: 2023/04/18 16:46:09 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (write(1, "Error: wrong number of arguments\n", 34), 0);
	if (!all_arg_are_int(argv))
		return (0);
	init_data(&data, argv);
}

long int	elapsed_time(struct timeval start)
{
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	if (actual.tv_sec == 0 && actual.tv_usec == 0)
		return (0);
	return (((actual.tv_sec - start.tv_sec) * 1000)
		+ (actual.tv_usec - start.tv_usec) / 1000);
}
