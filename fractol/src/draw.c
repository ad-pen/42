/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahouk <ad396.pen@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:11:32 by adahouk           #+#    #+#             */
/*   Updated: 2026/01/31 13:27:28 by adahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	*draw_mandelbrot(void *fractal_void)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)fractal_void;
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	return (NULL);
}

void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}

void	draw_burning_ship(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_burning_ship(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}
