/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:53:47 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/17 19:15:46 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	checkempty(int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	j = 0;
	flag = 0;
	while (i < argc)
	{
		flag = 0;
		if (argv[i][0] == ' ')
		{
			while (argv[i][j] != '\0')
			{
				if ((argv[i][j] >= 48 && argv[i][j] <= 57))
					flag = (1);
				j++;
			}
			if (flag == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	checkspace(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "", 10) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	checknumeric(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 2;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!((argv[i][j] >= 48 && argv[i][j] <= 57) || argv[i][j] == '-'
					|| argv[i][j] == ' ' || argv[i][j] == '+'
					|| argv[i][j] == '.'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checksign(int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 2;
	while (i < argc)
	{
		j = 0;
		flag = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (flag == 1 || argv[i][j + 1] == '\0')
					return (0);
				flag = 1;
			}
			else if (!((argv[i][j] >= 48 && argv[i][j] <= 57)
					|| argv[i][j] == '.'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checksign_between(int argc, char **argv)
{
	int	i;
	int	j;

	i = 2;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (j == 0)
					break ;
				else if ((argv[i][j - 1] >= 48 && argv[i][j - 1] <= 57)
					|| argv[i][j - 1] == '.')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
