/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahouk <adahouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:09:50 by adahouk           #+#    #+#             */
/*   Updated: 2025/08/25 18:51:40 by adahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else if (n < 0)
	{
		n = -n;
		write (fd, "-", 1);
	}
	if (n == 0)
		write (fd, "0", 1);
	if (n > 9)
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putnbr_fd (n % 10, fd);
	}
	if (n < 10 && n > 0)
	{
		c = n + '0';
		write (fd, &c, 1);
	}
}

/*int main ( )
{ int fd = open ("file.txt", O_WRONLY);
ft_putnbr_fd (100, fd); return 0;}*/