/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 18:58:31 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/03 14:08:25 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetriminos	*new_tetri(void)
{
	t_tetriminos	*new;

	if (!(new = (t_tetriminos*)malloc(sizeof(*new))))
		return (NULL);
	new->x = (int*)malloc(sizeof(int) * 4);
	new->y = (int*)malloc(sizeof(int) * 4);
	new->pos = (int*)malloc(sizeof(int) * 4);
	new->width = 0;
	new->height = 0;
	return (new);
}

static t_tetriminos	*get_tetriminos(char **file, char c)
{
	int				index;
	int				counter;
	t_tetriminos	*new;

	counter = 0;
	index = -1;
	if (!(new = new_tetri()))
		return (NULL);
	while (**file && (**file != '.' && **file != '#'))
		(*file)++;
	while (**file && ++index < 20)
	{
		if (**file == '#')
		{
			new->x[counter] = index % 5;
			new->y[counter] = index / 5;
			new->pos[counter] = index;
			new->width = ft_max_array(new->x, 4) - ft_min_array(new->x, 4) + 1;
			new->height = ft_max_array(new->y, 4) - ft_min_array(new->y, 4) + 1;
			counter++;
		}
		(*file)++;
	}
	new->c = c;
	return (new);
}

void				adjust_tetri_list(t_list *list)
{
	t_tetriminos	*current;
	int				i;
	int				minx;
	int				miny;

	while (list)
	{
		i = 0;
		current = list->content;
		minx = ft_min_array(current->x, 4);
		miny = ft_min_array(current->y, 4);
		while (i < 4)
		{
			current->x[i] -= minx;
			current->y[i] -= miny;
			current->pos[i] = current->x[i] + current->y[i] * 5;
			i++;
		}
		list = list->next;
	}
}

t_list				*build_list(char *file)
{
	t_list	*list;
	char	c;

	c = 'A';
	list = NULL;
	while (*file)
	{
		ft_lstaddback(&list, ft_lstnew(get_tetriminos(&file, c),
					sizeof(t_tetriminos)));
		c++;
	}
	return (list);
}
