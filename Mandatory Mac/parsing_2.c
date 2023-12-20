/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:56:39 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/19 12:46:20 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_points(int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 2;
	flag = 0;
	while (i < argc)
	{
		j = 0;
		flag = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '.')
			{
				if (flag == 1)
					return (0);
				flag = 1;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	checker(int argc, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
		return (1);
	else if ((ft_strncmp(argv[1], "julia", 6) == 0 && argc == 4))
	{
		if (checkempty(argc, argv) == 0)
			return (ft_printf("Julia parameters are empty\n"), 0);
		else if (checkspace(argc, argv) == 0)
			return (ft_printf("Julia parameters are empty\n"), 0);
		else if (checknumeric(argc, argv) == 0)
			return (ft_printf("Non numeric input detected\n"), 0);
		else if (checksign(argc, argv) == 0 || check_points(argc, argv) == 0)
			return (ft_printf("Non numeric input detected\n"), 0);
		else if (checksign_between(argc, argv) == 0)
			return (ft_printf("Non numeric input detected\n"), 0);
		else if (ft_atod(argv[2]) >= 5 || ft_atod(argv[3]) >= 5)
			return (ft_printf("Parameters too large\n"), 0);
		return (1);
	}
	else if ((ft_strncmp(argv[1], "help", 5) == 0))
		return (help(), (0));
	else
		return (ft_printf("Unknown command or missing/additonal "),
			ft_printf("parameters\n"), 0);
}

void	help(void)
{
	ft_printf("Greetings this fractol a projects that simulates ");
	ft_printf("different fractals (which are complex geometric ");
	ft_printf("shapes that exhibit self-similar patterns across ");
	ft_printf("different scales. \n\n");
	ft_printf("The avaiable fractals (aka commands) are \n");
	ft_printf("  `mandelbrot`  `julia real_parameter img_parameter'   \n\n");
	ft_printf("Controls: w(up) a(left)  s(right) d(down) l(color scheme) ");
	ft_printf("+(zoom in) -(zoom out) m(change iteration up) ");
	ft_printf("n(change iteration down)\n");
	ft_printf("Good julia examples: -0.79 0.15 | -0.162 1.04 | 0.3 -0.01");
	ft_printf(" | -1.476 0 | -0.12 -0.77 | 0.28 -0.008 \n");
}
