/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:39:21 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/17 19:10:54 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_mlx *mlx, int i)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	if (i == 1)
		render_fractal_mandle(mlx);
	else if (i == 2)
		render_fractal_julia(mlx);
	else if (i == 3)
		render_fractal_tricorn(mlx);
}

void	choice(t_mlx *mlx, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		inti_program(mlx, 1, 0, 0);
		render_fractal_mandle(mlx);
	}
	else if ((ft_strncmp(argv[1], "julia", 6) == 0))
	{
		inti_program(mlx, 2, ft_atod(argv[2]), ft_atod(argv[3]));
		render_fractal_julia(mlx);
	}
	else if ((ft_strncmp(argv[1], "tricorn", 8) == 0))
	{
		inti_program(mlx, 3, 0, 0);
		render_fractal_tricorn(mlx);
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 1 || checker(argc, argv) == 0)
		return (0);
	choice(&mlx, argv);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, movement, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, destroy_mlx, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mouse_scroll, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
