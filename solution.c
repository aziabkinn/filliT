/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:39:49 by aziabkin          #+#    #+#             */
/*   Updated: 2018/04/23 14:39:51 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check(t_figures *lst, char **map, int i, int j)
{
	int			k;
	int			flag;
	int			max_map;

	k = 0;
	flag = 0;
	max_map = 0;
	while (map[0][max_map])
		max_map++;
	while (k < 4)
	{
		if ((X >= max_map) || (X < 0) || (Y < 0) || (Y >= max_map))
			return (0);
		k++;
	}
	k = 0;
	while (k < 4)
	{
		if (map[Y][X] == '.')
			flag++;
		k++;
	}
	if (flag == 4 && fill_figure(lst, map, i, j))
		return (1);
	return (0);
}

int				fill_figure(t_figures *lst, char **map, int i, int j)
{
	int			k;

	k = 0;
	while (k < 4)
	{
		if (map[Y][X] == '.')
			map[Y][X] = lst->letter;
		else
			return (0);
		k++;
	}
	return (1);
}

char			**put_dots(t_figures *lst, char **map, int max_map)
{
	int			i;
	int			j;

	i = 0;
	while (i < max_map)
	{
		j = 0;
		while (j < max_map)
		{
			if (map[i][j] == lst->letter)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int				fillit(t_figures *lst, char **map, int max_map)
{
	int			i;
	int			j;

	i = 0;
	if (!lst)
		return (1);
	while (i < max_map)
	{
		j = 0;
		while (j < max_map)
		{
			if (check(lst, map, i, j))
			{
				if (fillit(lst->next, map, max_map))
					return (1);
				map = put_dots(lst, map, max_map);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char			**create_map(int n)
{
	int			i;
	char		**map;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	map[n] = NULL;
	while (i < n)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (n + 1))))
		{
			free(map);
			return (NULL);
		}
		ft_memset(map[i], '.', n);
		map[i][n] = '\0';
		i++;
	}
	return (map);
}
