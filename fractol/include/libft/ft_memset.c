/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahouk <adahouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:17:32 by adahouk           #+#    #+#             */
/*   Updated: 2025/08/30 17:05:53 by adahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*u;
	size_t			i;

	u = s;
	i = 0;
	while (i < n)
	{
		u[i] = c;
		i++;
	}
	return (u);
}

// int main ()
// {
// 	int str[] = {0,0,0,0,0};
// 	int *strr;
// 	int i = 0;
// 	strr = (int *)ft_memset (str, '1', 20);
// 	while (i < 5)
// 	{
// 		printf ("%d\n", strr[i]);
// 		i++;
// 	}
// }