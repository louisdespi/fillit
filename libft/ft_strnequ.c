/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:36:21 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/22 18:17:38 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	i = 1;
	while (i < n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		i++;
	}
	if (*s1 != *s2)
		return (0);
	return (1);
}
