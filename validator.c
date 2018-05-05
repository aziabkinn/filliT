/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:40:09 by aziabkin          #+#    #+#             */
/*   Updated: 2018/04/23 14:49:50 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			validator(char *buf, int size)
{
	int		arr[4];

	arr[0] = 4;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	while (arr[0] < size)
	{
		if (buf[arr[0]] != '\n')
			return (0);
		arr[0] += 5;
	}
	arr[0] = -1;
	while (++arr[0] < size)
	{
		(buf[arr[0]] == '.') ? arr[1]++ : (0);
		(buf[arr[0]] == '#') ? arr[2]++ : (0);
		(buf[arr[0]] == '\n') ? arr[3]++ : (0);
	}
	if (arr[1] != 12 || arr[2] != 4 || arr[3] != 4)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

int			correct_form(char *buf, int size)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (buf[i] == '#')
		{
			(buf[i - 1] == '#') ? count++ : (0);
			if (buf[i + 1] == '#')
				count++;
			if (buf[i - 5] == '#')
				count++;
			if (buf[i + 5] == '#')
				count++;
		}
		i++;
	}
	if (count != 6 && count != 8)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

int			check_array_of_figs(char *buf, int size, int num_figs)
{
	char	**splitted_buff;
	int		i;
	int		valid_file;

	i = 20;
	valid_file = 1;
	while (i < size)
	{
		buf[i] = '&';
		i += 21;
	}
	splitted_buff = ft_strsplit(buf, '&');
	i = -1;
	while (++i <= num_figs - 1)
		if (validator(splitted_buff[i], (int)ft_strlen(splitted_buff[i])))
			valid_file *= 1;
		else
			return (0);
	i = -1;
	while (++i <= num_figs - 1)
		if (correct_form(splitted_buff[i], (int)ft_strlen(splitted_buff[i])))
			valid_file *= 1;
		else
			valid_file *= 0;
	return (valid_file);
}
