/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:21:29 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/29 19:22:25 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*build_char_map(int size)
{
	char	*map;
	int		index;
	int		counter;

	if (!(map = (char*)malloc(sizeof(*map) * (size * size + size + 1))))
		return (NULL);
	index = 0;
	counter = 0;
	while (index < size * size + size)
	{
		if (counter == size)
		{
			map[index] = '\n';
			counter = 0;
		}
		else
		{
			map[index] = '.';
			counter++;
		}
		index++;
	}
	map[size * size + size] = '\0';
	return (map);
}

t_map		*new_map(int size)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(*map))))
		return (NULL);
	if (!(map->map_str = build_char_map(size)))
		return (NULL);
	map->size = size;
	map->count_tetri = 0;
	return (map);
}
