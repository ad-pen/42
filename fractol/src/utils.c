/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahouk <ad396.pen@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:30:38 by adahouk           #+#    #+#             */
/*   Updated: 2026/01/31 16:25:30 by adahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}

double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

void	change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}

double	ft_atof(char *s)
{
	double	res;
	double	pow;
	int		sig;

	res = 0.0;
	pow = 1.0;
	sig = 1;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sig = -1;
	while (*s >= '0' && *s <= '9')
		res = res * 10 + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s++ - '0');
		pow *= 10;
	}
	return (res * sig / pow);
}
