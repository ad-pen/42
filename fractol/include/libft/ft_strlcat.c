/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahouk <adahouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:49:04 by adahouk           #+#    #+#             */
/*   Updated: 2025/08/18 13:12:19 by adahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	u;
	unsigned int	length;

	i = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	length = i;
	u = 0;
	while (i + 1 < size && src[u] != '\0')
	{
		dest[i] = src[u];
		i++;
		u++;
	}
	while (src[u] != '\0')
		u++;
	if (length < size)
		dest[i] = '\0';
	return (length + u);
}
