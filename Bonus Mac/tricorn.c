/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:04:06 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/17 19:04:32 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal_tricorn(t_mlx *mlx)
{
	int			i;
	int			x;
	int			y;
	t_movemet	*move;

	move = &mlx->move;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			i = tricorn_set(mlx, (-2.0 + x * (4.0 / WIDTH)) * move->zoom
					+ move->offset_x, (2.0 - y * (4.0 / HEIGHT)) * move->zoom
					+ move->offset_y);
			if (i == move->iterations)
				mlx->data[y * WIDTH + x] = i * move->color_scheme[0];
			else
				mlx->data[y * WIDTH + x] = i * move->color_scheme[1];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

int	tricorn_set(t_mlx *mlx, double cr, double ci)
{
	double		zr;
	double		zi;
	int			i;
	double		temp;
	t_movemet	*move;

	move = &mlx->move;
	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (zr * zr + zi * zi <= 4 && i < move->iterations)
	{
		temp = zr * zr - zi * zi + cr;
		zi = -2 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}
