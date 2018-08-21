/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:00:52 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/18 16:10:10 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*tag;

	tag = s1;
	i = 0;
	while (*s1)
		s1++;
	while (i++ < n && *s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (tag);
}
