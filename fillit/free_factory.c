/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_factory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 10:54:54 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/03 14:08:43 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(t_map **emap)
{
	free((*emap)->map_str);
	free(*emap);
	*emap = NULL;
}

void	free_tetriminos(void *tetri, size_t size)
{
	t_tetriminos *t;

	(void)size;
	t = (t_tetriminos*)tetri;
	free(t->x);
	free(t->y);
	free(t->pos);
	free(t);
}
