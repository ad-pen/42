/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahouk <adahouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:51:35 by adahouk           #+#    #+#             */
/*   Updated: 2025/08/27 16:26:00 by adahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] && set[j] != s1[i])
			j++;
		if (set[j] == '\0')
			break ;
		i++;
	}
	k = ft_strlen(s1);
	while (k - 1 > i)
	{
		j = 0;
		while (set[j] != s1[k - 1] && set[j])
			j++;
		if (set[j] == '\0')
			break ;
		k--;
	}
	return (ft_substr(s1, i, k - i));
}
