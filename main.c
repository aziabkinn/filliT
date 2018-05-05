/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:39:27 by aziabkin          #+#    #+#             */
/*   Updated: 2018/04/24 14:35:35 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				prov(int argc, char *av)
{
	if (doc_size(argc, av) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	if (((doc_size(argc, av) + 1) % 21 > 0) ||
		doc_size(argc, av) < 20 || doc_size(argc, av) > 545)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

void			print_map(char **map)
{
	int			i;

	i = -1;
	while (map[++i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}

char			**put_figures(t_figures *lst)
{
	int			n;
	char		**map;

	n = 2;
	map = create_map(n);
	while (!(fillit(lst, map, n)))
		map = create_map(++n);
	return (map);
}

void			ft_do(char *buf, int fd)
{
	t_figures	*lst;
	char		**splitted_buf;

	lst = NULL;
	splitted_buf = ft_strsplit(buf, '&');
	replace_hashs(splitted_buf, fd);
	lst = ft_create_struct(splitted_buf, fd);
	set_coords(lst);
	set_vectors(lst);
	print_map(put_figures(lst));
}

int				main(int argc, char **argv)
{
	char		*buf;
	int			fd;
	int			size;

	if (argc == 2)
	{
		if (!prov(argc, argv[1]))
			return (0);
		size = doc_size(argc, argv[1]);
		buf = ft_memalloc(size + 1);
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putendl("error");
			return (0);
		}
		read_file(fd, buf, size);
		buf[size] = '\0';
		fd = (size + 1) / 21;
		if (!check_array_of_figs(buf, size, fd))
			return (0);
		ft_do(buf, fd);
	}
	else
		ft_putendl("usage: ./fillit [filename]");
	return (0);
}
