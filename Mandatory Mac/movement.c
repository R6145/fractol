/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:59:46 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/18 16:29:15 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// +
// -
// m
// n
// esc
int	movement(int keystroke, t_mlx *mlx)
{
	t_movemet	*move;

	move = &mlx->move;
	if (keystroke == 24)
	{
		move->zoom = move->zoom / 1.1;
		move->offset_y = move->offset_y + (0.15 + move->offset_fix)
			* move->zoom;
		move->offset_x = move->offset_x + (0.15 + move->offset_fix)
			* move->zoom;
	}
	movement_2(keystroke, mlx);
	return (0);
}

int	movement_2(int keystroke, t_mlx *mlx)
{
	t_movemet	*move;

	move = &mlx->move;
	if (keystroke == 27)
	{
		move->zoom = move->zoom * 1.1;
		move->offset_y = move->offset_y - (0.15 + move->offset_fix)
			* move->zoom;
		move->offset_x = move->offset_x - (0.15 + move->offset_fix)
			* move->zoom;
	}
	else if (keystroke == 46)
		move->iterations++;
	else if (keystroke == 45)
		move->iterations--;
	else if (keystroke == 53)
		destroy_mlx(mlx);
	render(mlx, move->fractol_choice);
	return (0);
}

int	mouse_scroll(int scroll, int x, int y, t_mlx *mlx)
{
	t_movemet	*move;

	move = &mlx->move;
	if (scroll == 4)
	{
		move->zoom = move->zoom / 1.1;
		move->offset_y = move->offset_y + (0.15 + move->offset_fix)
			* move->zoom;
		move->offset_x = move->offset_x + (0.15 + move->offset_fix)
			* move->zoom;
	}
	mouse_scroll_2(scroll, x, y, mlx);
	return (0);
}

int	mouse_scroll_2(int scroll, int x, int y, t_mlx *mlx)
{
	t_movemet	*move;

	move = &mlx->move;
	if (x < -100 || y < -100)
		return (0);
	if (scroll == 5)
	{
		move->zoom = move->zoom * 1.1;
		move->offset_y = move->offset_y - (0.15 + move->offset_fix)
			* move->zoom;
		move->offset_x = move->offset_x - (0.15 + move->offset_fix)
			* move->zoom;
	}
	render(mlx, move->fractol_choice);
	return (0);
}
