/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 10:57:13 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/03 11:45:44 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*fillit(t_list *list)
{
	int				i;
	t_map			*map;
	t_tetriminos	*t;
	int				counter;

	counter = 0;
	t = list->content;
	i = ft_max(t->height, t->width);
	map = new_map(i);
	while (!(fill_map(&map, list, ft_lstsize(list), &counter)))
	{
		i++;
		free_map(&map);
		map = new_map(i);
	}
	ft_putstr("count tetriminos placed : ");
	ft_putnbr(counter);
	ft_putchar('\n');
	return (map);
}
