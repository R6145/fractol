/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:02:53 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/17 19:03:47 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal_julia(t_mlx *mlx)
{
	t_movemet	*move;
	int			i;
	int			x;
	int			y;

	move = &mlx->move;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			i = julia_set(mlx, (3.0 * (x - WIDTH / 2) * move->zoom / (0.5
							* WIDTH)) + move->offset_x, (3.0 * (y - HEIGHT / 2)
						* move->zoom / (0.5 * HEIGHT)) - move->offset_y);
			mlx->data[y * WIDTH + x] = i * move->color_scheme[0];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

int	julia_set(t_mlx *mlx, double zr, double zi)
{
	int			i;
	double		temp;
	t_movemet	*move;

	move = &mlx->move;
	i = 0;
	while (i < move->iterations && zr * zr + zi * zi <= 4.0)
	{
		temp = zr * zr - zi * zi + move->cr;
		zi = 2.0 * zr * zi + move->ci;
		zr = temp;
		i++;
	}
	return (i);
}
