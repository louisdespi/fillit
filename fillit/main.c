/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:18:51 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/03 14:10:06 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*file;
	t_list	*list;
	t_map	*map;

	list = NULL;
	if (argc != 2)
	{
		ft_putendl_fd("usage: fillit source_file", 2);
		return (1);
	}
	if (((file = ft_read_file(argv[1])) && !is_file_valid(file)) || !file)
	{
		ft_putendl("error");
		free(file);
		return (1);
	}
	list = build_list(file);
	adjust_tetri_list(list);
	map = fillit(list);
	ft_lstdel(&list, free_tetriminos);
	ft_putstr(map->map_str);
	free_map(&map);
	free(file);
	return (0);
}
