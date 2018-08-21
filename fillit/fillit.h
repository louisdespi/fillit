/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:17:40 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/03 11:42:13 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# define BUF_SIZE 545

typedef struct	s_tetriminos
{
	int		*x;
	int		*y;
	int		*pos;
	int		width;
	int		height;
	char	c;
}				t_tetriminos;

typedef struct	s_map
{
	char	*map_str;
	int		size;
	int		count_tetri;
}				t_map;

void			adjust_tetri_list(t_list *list);
t_list			*build_list(char *file);
char			*ft_read_file(char *path);
t_map			*new_map(int size);
int				fill_map(t_map **map, t_list *list, int count_tetriminos, int *counter);
t_map			*fillit(t_list *list);
int				is_file_valid(char *s);
void			free_map(t_map **emap);
void			free_tetriminos(void *tetri, size_t size);

#endif
