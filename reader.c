/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:39:40 by aziabkin          #+#    #+#             */
/*   Updated: 2018/04/23 14:39:41 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			doc_size(int argc, char *path)
{
	int		fd;
	int		i;
	char	buf;

	argc = 0;
	i = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	while (read(fd, &buf, 1) != '\0')
		i++;
	if (close(fd) == -1)
		return (0);
	return (i);
}

void		read_file(int fd, char *buf, int size)
{
	read(fd, buf, size);
	if (close(fd) == -1)
		return ;
}
