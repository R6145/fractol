/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:57:54 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/17 19:15:55 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *str)
{
	double	sign;
	int		i;
	double	tot;

	i = 0;
	sign = 1;
	tot = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		str++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		tot = tot * 10 + str[i] - '0';
		i++;
	}
	return (ft_atod_2(str, i, tot, sign));
}

double	ft_atod_2(const char *str, int i, double tot, double sign)
{
	double	fraction;
	double	divisor;

	if (str[i] == '.')
	{
		fraction = 0.0;
		divisor = 1.0;
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			fraction = fraction * 10.0 + (str[i++] - '0');
			divisor = divisor * 10.0;
		}
		tot = tot + fraction / divisor;
	}
	return (tot * sign);
}
