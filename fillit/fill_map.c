/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:28:19 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/03 11:45:08 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		*deduce_pos(t_tetriminos *tetri, int size, int pos)
{
	int		*tab;
	int		i;

	if (!(tab = (int*)malloc(sizeof(*tab) * 4)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		tab[i] = pos + tetri->x[i] + tetri->y[i] * (size + 1) - tetri->x[0];
		i++;
	}
	return (tab);
}

static int		is_applicable(t_tetriminos *tetri, t_map *map, int pos)
{
	int		size;
	int		*tab;
	int		i;

	size = map->size;
	if (ft_max_array(tetri->x, 4) - tetri->x[0] + pos % (size + 1) > size
			|| pos / (size + 1) + tetri->height > size
			|| tetri->x[0] - ft_min_array(tetri->x, 4) > pos % (size + 1))
		return (0);
	if (!(tab = deduce_pos(tetri, size, pos)))
		return (0);
	i = 0;
	while (i < 4)
	{
		if ((map->map_str[tab[i]]) != '.')
			return (0);
		i++;
	}
	return (1);
}

static void		add_tetri(t_tetriminos *tetri, t_map *map, int pos)
{
	int		*tab;
	int		i;

	if (!(tab = deduce_pos(tetri, map->size, pos)))
		return ;
	i = 0;
	while (i < 4)
	{
		map->map_str[tab[i]] = tetri->c;
		i++;
	}
	map->count_tetri++;
}

static t_map	*copy_map(t_map *map)
{
	t_map	*copy;

	if (!(copy = (t_map*)malloc(sizeof(*copy))))
		return (NULL);
	if (!(copy->map_str = ft_strdup(map->map_str)))
		return (NULL);
	copy->size = map->size;
	copy->count_tetri = map->count_tetri;
	return (copy);
}

int				fill_map(t_map **map, t_list *list, int count_tetriminos, int *counter)
{
	int		pos;
	t_map	*tmp;

	if ((*map)->count_tetri == count_tetriminos)
		return (1);
	pos = 0;
	tmp = copy_map(*map);
	while (pos < ((*map)->size + 1) * (*map)->size)
	{
		if (is_applicable(list->content, *map, pos))
		{
			add_tetri(list->content, *map, pos);
			ft_putendl((*map)->map_str);
			(*counter)++;
			if (list && fill_map(map, list->next, count_tetriminos, counter))
				return (1);
			free_map(map);
			*map = copy_map(tmp);
		}
		pos++;
	}
	*map = tmp;
	return (0);
}
