/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:59:46 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/18 19:56:58 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// w
// s
// d
// a
// +
// -
// m
// n
// l
// esc
int	movement(int keystroke, t_mlx *mlx)
{
	t_movemet	*move;

	move = &mlx->move;
	if (keystroke == 13)
		move->offset_y = move->offset_y - 0.025 * move->zoom;
	else if (keystroke == 1)
		move->offset_y = move->offset_y + 0.025 * move->zoom;
	else if (keystroke == 2)
		move->offset_x = move->offset_x + 0.025 * move->zoom;
	else if (keystroke == 0)
		move->offset_x = move->offset_x - 0.025 * move->zoom;
	else if (keystroke == 24)
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
	else if (keystroke == 37)
		change_scheme(mlx);
	else if (keystroke == 53)
		destroy_mlx(mlx);
	render(mlx, move->fractol_choice);
	return (0);
}

int	mouse_scroll(int scroll, int x, int y, t_mlx *mlx)
{
	t_movemet	*move;
	double		mouse_x;
	double		mouse_y;

	move = &mlx->move;
	mouse_x = (double)x / WIDTH * 2.6 - 1.25;
	mouse_y = (double)y / HEIGHT * 2.6 - 1.25;
	if (scroll == 4)
	{
		move->zoom = move->zoom / 1.1;
		if (move->offset_fix == 0)
			move->offset_y = move->offset_y + mouse_y * move->zoom;
		else
			move->offset_y = move->offset_y - mouse_y * move->zoom;
		move->offset_x = move->offset_x + mouse_x * move->zoom;
	}
	mouse_scroll_2(scroll, x, y, mlx);
	return (0);
}

int	mouse_scroll_2(int scroll, int x, int y, t_mlx *mlx)
{
	t_movemet	*move;
	double		mouse_x;
	double		mouse_y;

	move = &mlx->move;
	mouse_x = (double)x / WIDTH * 2.6 - 1.25;
	mouse_y = (double)y / HEIGHT * 2.6 - 1.25;
	if (scroll == 5)
	{
		move->zoom = move->zoom * 1.1;
		if (move->offset_fix == 0)
			move->offset_y = move->offset_y + mouse_y * move->zoom;
		else
			move->offset_y = move->offset_y - mouse_y * move->zoom;
		move->offset_x = move->offset_x - mouse_x * move->zoom;
	}
	render(mlx, move->fractol_choice);
	return (0);
}
