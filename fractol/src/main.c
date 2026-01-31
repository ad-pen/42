/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahouk <ad396.pen@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:04:11 by adahouk           #+#    #+#             */
/*   Updated: 2026/01/31 16:30:59 by adahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_is_float(char *s)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (dot)
				return (0);
			dot = 1;
		}
		else if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	init_julia_values(t_fractal *fractal, int argc, char **argv)
{
	if (ft_strncmp(argv[1], "julia", 5) != 0)
		return ;
	if (argc == 4)
	{
		fractal->cx = ft_atof(argv[2]);
		fractal->cy = ft_atof(argv[3]);
	}
	else
	{
		fractal->cx = -0.745429;
		fractal->cy = 0.05;
	}
}

int	draw_fractal(t_fractal *fractal, char *name)
{
	if (ft_strncmp(name, "mandel", 6) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(name, "julia", 5) == 0)
		draw_julia(fractal);
	else if (ft_strncmp(name, "ship", 4) == 0)
		draw_burning_ship(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (argc == 2 && !ft_strncmp(argv[1], "mandel", 7))
		return (1);
	if (argc == 2 && !ft_strncmp(argv[1], "ship", 5))
		return (1);
	if (!ft_strncmp(argv[1], "julia", 6) && (argc == 2 || argc == 4))
	{
		if (argc == 2 || (ft_is_float(argv[2]) && ft_is_float(argv[3])))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (check_args(argc, argv))
	{
		fractal = malloc(sizeof(t_fractal));
		if (!fractal)
    		exit(1);
		init_fractal(fractal);
		init_mlx(fractal);
		init_julia_values(fractal, argc, argv);
		mlx_key_hook(fractal->window, key_hook, fractal);
		mlx_mouse_hook(fractal->window, mouse_hook, fractal);
		mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
		draw_fractal(fractal, argv[1]);
		mlx_loop(fractal->mlx);
	}
	else
	{
		ft_putstr_fd("Usage: ./fractol <mandel/julia/ship> [float] [float]\n",
			1);
		exit(1);
	}
	return (0);
}
