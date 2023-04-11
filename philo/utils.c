/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:35:11 by xalbizu-          #+#    #+#             */
/*   Updated: 2023/03/13 16:35:27 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	long int	aux;
	char		caux[12];
	ssize_t		i;

	caux[0] = '0';
	aux = n;
	i = 0;
	if (aux < 0)
	{
		aux *= -1;
		write(1, "-", 1);
	}
	while (aux > 9)
	{
		caux[i] = (aux % 10) + '0';
		aux = aux / 10;
		i++;
	}
	caux[i] = (aux % 10) + '0';
	i++;
	caux[i] = '\0';
	while (0 < i--)
	{
		write(1, &caux[i], 1);
	}
}