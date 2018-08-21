/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:03:44 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/01 12:06:41 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_newline(char *s, int *i, int *j)
{
	if (*i == 4)
	{
		if (*s != '\n')
			return (0);
		*i = 0;
	}
	else
		(*i)++;
	if (*j == 20)
	{
		if (*s != '\n')
			return (0);
		*i = 0;
		*j = 0;
	}
	else
		(*j)++;
	return (1);
}

static int		check_file_form(char *s)
{
	int		i;
	int		j;
	int		index;

	i = 0;
	j = 0;
	index = 0;
	while (*s)
	{
		if (*s != '.' && *s != '\n' && *s != '#')
			return (0);
		if (!check_newline(s, &i, &j))
			return (0);
		s++;
		index++;
	}
	return ((index + 1) % 21 == 0);
}

static int		check_tetri_form(char *s)
{
	int		links;
	int		index;
	int		count;

	links = 0;
	index = 0;
	count = 0;
	while (index <= 19)
	{
		if (*s == '#')
		{
			count++;
			if ((index) % 5 != 0 && *(s - 1) == '#')
				links++;
			if ((index - 3) % 5 != 0 && *(s + 1) == '#')
				links++;
			if (index >= 5 && *(s - 5) == '#')
				links++;
			if (index < 15 && *(s + 5) == '#')
				links++;
		}
		index++;
		s++;
	}
	return (links >= 6 && count == 4);
}

int				is_file_valid(char *s)
{
	if (!(check_file_form(s)))
		return (0);
	while (*s)
	{
		if (!(check_tetri_form(s)))
			return (0);
		s += 20;
		if (*s)
			s++;
	}
	return (1);
}
