/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:18:43 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/27 15:12:29 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read_file(char *path)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		read_bytes;
	char	*to_ret;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	if ((read_bytes = read(fd, buf, BUF_SIZE)) == -1)
		return (NULL);
	buf[read_bytes] = '\0';
	to_ret = ft_strdup(buf);
	if ((read_bytes = read(fd, buf, BUF_SIZE)) != 0)
		return (NULL);
	if (close(fd) != 0)
		return (NULL);
	return (to_ret);
}
