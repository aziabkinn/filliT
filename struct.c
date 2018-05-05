/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:43:18 by aziabkin          #+#    #+#             */
/*   Updated: 2018/04/23 14:43:20 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			replace_hashs(char **splitted_buf, int num_figs)
{
	int			i;
	int			j;

	i = 0;
	while (i < num_figs)
	{
		j = 0;
		while (splitted_buf[i][j] != '\0')
		{
			if (splitted_buf[i][j] == '#')
				splitted_buf[i][j] = i + 65;
			j++;
		}
		i++;
	}
}

void			ft_create_struct_2(char **spl_b, t_figures *lst, int i)
{
	int			j;
	int			x;
	int			y;

	j = 0;
	y = 0;
	x = 0;
	while (j < 20)
	{
		if (x > 3)
			x = 0;
		if (spl_b[i][j] == '\n')
		{
			y++;
			x--;
		}
		else
			lst->figure[y][x] = spl_b[i][j];
		x++;
		j++;
	}
}

t_figures		*ft_create_struct(char **splitted_buff, int figures)
{
	int			i;
	t_figures	*lst;
	t_figures	*temp;

	i = 0;
	if (!(lst = (t_figures*)malloc(sizeof(t_figures))))
		return (NULL);
	temp = lst;
	while (i < figures)
	{
		ft_create_struct_2(splitted_buff, lst, i);
		lst->letter = i + 65;
		i++;
		if (i < figures)
		{
			if (!(lst->next = (t_figures*)malloc(sizeof(t_figures))))
				return (NULL);
			lst = lst->next;
		}
	}
	lst->next = NULL;
	return (temp);
}

void			set_coords(t_figures *lst)
{
	int			i;
	int			j;
	int			i_x;

	while (lst)
	{
		i_x = 0;
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (ft_isalpha(lst->figure[i][j]))
				{
					lst->coords_x[i_x] = j;
					lst->coords_y[i_x] = i;
					i_x++;
				}
				j++;
			}
			i++;
		}
		lst = lst->next;
	}
}

void			set_vectors(t_figures *lst)
{
	int			i;
	int			diff_x;
	int			diff_y;

	while (lst)
	{
		i = 0;
		diff_x = lst->coords_x[0];
		diff_y = lst->coords_y[0];
		while (i < 4)
		{
			lst->coords_x[i] -= diff_x;
			lst->coords_y[i] -= diff_y;
			i++;
		}
		lst = lst->next;
	}
}
