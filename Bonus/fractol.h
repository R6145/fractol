/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:47:26 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/17 19:43:50 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "printf/ft_printf.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_movement
{
	double		scale;
	double		offset_x;
	double		offset_y;
	double		offset_fix;
	double		zoom;
	int			iterations;
	int			color_scheme[3];
	double		cr;
	double		ci;
	int			fractol_choice;
}				t_movemet;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	t_movemet	move;
}				t_mlx;

// initlzation and mlx
void			init_mlx(t_mlx *mlx);
int				destroy_mlx(t_mlx *mlx);
void			init_movement(t_movemet *move);
void			inti_program(t_mlx *mlx, int c, double cr, double ci);
// rendering sets
void			render(t_mlx *mlx, int i);
void			render_fractal_mandle(t_mlx *mlx);
void			render_fractal_julia(t_mlx *mlx);
void			render_fractal_tricorn(t_mlx *mlx);
int				mandelbrot_set(double cr, double ci, int iterations);
int				julia_set(t_mlx *mlx, double zr, double zi);
int				tricorn_set(t_mlx *mlx, double cr, double ci);
void			change_scheme(t_mlx *mlx);
// camera movement
int				movement(int keystroke, t_mlx *mlx);
int				movement_2(int keystroke, t_mlx *mlx);
int				mouse_scroll(int scroll, int x, int y, t_mlx *mlx);
int				mouse_scroll_2(int scroll, int x, int y, t_mlx *mlx);
// parsing
double			ft_atod(const char *str);
double			ft_atod_2(const char *str, int i, double tot, double sign);
int				checker(int argc, char **argv);
int				checkempty(int argc, char **argv);
int				checkspace(int argc, char **argv);
int				checknumeric(int argc, char **argv);
int				checksign(int argc, char **argv);
int				checksign_between(int argc, char **argv);
int				check_points(int argc, char **argv);
// main util
void			choice(t_mlx *mlx, char **argv);
void			help(void);

#endif