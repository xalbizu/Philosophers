/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:00:53 by xalbizu-          #+#    #+#             */
/*   Updated: 2023/03/13 16:30:23 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosophers.h"

int	main(int argc, char *argv[])
{
	struct timeval	start;
	t_philo			*philosophers;
	int				num_philosophers;

	gettimeofday(&start, NULL);
	if (argc < 5 || argc > 6)
	{
		write(1, "Error: wrong number of arguments\n", 34);
		return (0);
	}
	if (!all_arg_are_int(argv))
		return (0);
	num_philosophers = ft_atoi(argv[1]);
	philosophers = malloc(num_philosophers * sizeof(t_philo));
	if (!philosophers)
		return (write(1, "Error: unable to allocate memory\n", 33), 0);
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

long int	ft_atoi(const char *str)
{
	int			count;
	long int	result;
	int			isnegative;

	result = 0;
	isnegative = 0;
	count = 0;
	while (str[count] == ' ' || str[count] == '\n' || str[count] == '\r'
		|| str[count] == '\f' || str[count] == '\t' || str[count] == '\v')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			isnegative = 1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		result *= 10;
		result += str[count] - '0';
		count++;
	}
	if (isnegative == 1)
		result *= -1;
	return (result);
}
