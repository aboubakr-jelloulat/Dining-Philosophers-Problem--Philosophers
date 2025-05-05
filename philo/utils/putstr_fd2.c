/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:58:51 by ajelloul          #+#    #+#             */
/*   Updated: 2025/05/05 19:58:52 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt++])
		;
	return (cnt);
}

int	putstr_fd2(const char *str_err)
{
	write(2, RED, ft_strlen(RED));
	write(2, str_err, ft_strlen(str_err));
	write(2, RESET, ft_strlen(RESET));
	return (1);
}
