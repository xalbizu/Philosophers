/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:00:53 by xalbizu-          #+#    #+#             */
/*   Updated: 2023/03/13 13:49:07 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosophers.h"

int	main(int argc, char *argv[])
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	if (argc < 5 || argc > 6)
	{
		write(1, "Error: wrong number of arguments\n", 34);
		return (0);
	}
	if (!all_arg_are_int(argv))
		return (0);
}

long int	elapsed_time(struct timeval start)
{
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	return (((actual.tv_sec - start.tv_sec) * 1000)
		+ (actual.tv_usec - start.tv_usec) / 1000);
}

int	all_arg_are_int(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(1, "Error: all arguments must be + integers\n", 41);
				return (0);
			}
		}
	}
	return (1);
}
