/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:55:45 by ajelloul          #+#    #+#             */
/*   Updated: 2025/05/05 19:55:46 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_space(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			i;

	i = 0;
	res = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '0')
		i++;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (-1);
		if (res > INT_MAX)
			return (-1);
		if (res < INT_MIN)
			return (-1);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((int)(res));
}
