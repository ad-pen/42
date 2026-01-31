/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahouk <adahouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:01:54 by adahouk           #+#    #+#             */
/*   Updated: 2025/08/25 18:28:14 by adahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	int		l;
	char	*str;

	str = (char *)s;
	len = 0;
	while (str[len] != '\0')
		len++;
	l = len;
	len--;
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return (str + len);
		len--;
	}
	if ((char)c == 0)
		return (str + l);
	return (NULL);
}
