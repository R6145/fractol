/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:01:08 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/19 14:08:43 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_movement(t_movemet *move)
{
	move->scale = 0.004;
	move->offset_x = -2.25;
	move->offset_y = -1.5;
	move->zoom = 1;
	move->iterations = 50;
	move->color_scheme[0] = 0x191970;
	move->color_scheme[1] = 0x800032;
	move->color_scheme[2] = 0x007721;
	move->cr = 0;
	move->ci = 0;
	move->offset_fix = 0;
}

void	inti_program(t_mlx *mlx, int c, double cr, double ci)
{
	t_movemet	*move;

	move = &mlx->move;
	init_mlx(mlx);
	init_movement(move);
	if (c == 1)
		move->fractol_choice = 1;
	else if (c == 2)
	{
		move->fractol_choice = 2;
		move->cr = cr;
		move->ci = ci;
		move->offset_x = 0;
		move->offset_y = 0;
		move->offset_fix = -0.15;
	}
}
