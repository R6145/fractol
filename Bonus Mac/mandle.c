/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:01:38 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/17 19:02:31 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal_mandle(t_mlx *mlx)
{
	int			i;
	int			x;
	int			y;
	t_movemet	*move;

	y = 0;
	move = &mlx->move;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			i = mandelbrot_set(x * move->scale * move->zoom + move->offset_x, y
					* move->scale * move->zoom + move->offset_y,
					move->iterations);
			mlx->data[y * WIDTH + x] = i * move->color_scheme[0];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

int	mandelbrot_set(double cr, double ci, int iterations)
{
	double	zr;
	double	zi;
	int		i;
	double	temp;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < iterations && zr * zr + zi * zi < 4.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}
