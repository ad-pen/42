/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahouk <ad396.pen@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:53:17 by adahouk           #+#    #+#             */
/*   Updated: 2026/01/31 15:40:07 by adahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <pthread.h>

# define SIZE 700
# define THREAD_WIDTH 7
# define THREAD_NUMBER 100

// KEYCODES
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define R 114
# define C 99
# define H 104
# define J 106
# define P 112
# define M 109

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

// utils.c
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);
int			exit_fractal(t_fractal *fractal);
double		generate_random_c(void);
void		change_iterations(t_fractal *fractal, int key_code);
double		ft_atof(char *s);

// init.c
void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);

// mandelbrot.c
void		calculate_mandelbrot(t_fractal *fractal);

// julia.c
void		calculate_julia(t_fractal *fractal);

// burning_ship.c
void		calculate_burning_ship(t_fractal *fractal);

// main.c
int			draw_fractal(t_fractal *fractal, char *query);
void		init_julia_values(t_fractal *fractal, int argc, char **argv);
int			check_args(int argc, char **argv);
int			ft_is_float(char *s);

// mouse_and_keys.c
int			key_hook(int key_code, t_fractal *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

// draw.c
void		*draw_mandelbrot(void *fractal_void);
void		draw_julia(t_fractal *fractal);
void		draw_burning_ship(t_fractal *fractal);

#endif
