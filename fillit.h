/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:39:13 by aziabkin          #+#    #+#             */
/*   Updated: 2018/04/24 15:25:43 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define X lst->coords_x[k] + j
# define Y lst->coords_y[k] + i

typedef	struct			s_figures
{	int					letter;
	char				figure[4][4];
	int					coords_x[4];
	int					coords_y[4];
	struct s_figures	*next;
}						t_figures;

int						doc_size(int argc, char *path);
void					read_file(int fd, char *buf, int size);
int						validator(char *buf, int size);
int						correct_form(char *buf, int size);
int						check_array_of_figs(char *buf, int size, int num_figs);
void					replace_hashs(char **splitted_buf, int num_figs);
char					**create_map(int n);
t_figures				*ft_create_struct(char **splitted_buff, int fd);
void					print_figure(t_figures *lst);
void					set_coords(t_figures *lst);
void					set_vectors(t_figures *lst);
char					**put_figures(t_figures *lst);
void					print_map(char **map);
char					**fill_field(t_figures *lst, char **map, int max_map);
int						fillit(t_figures *lst, char **map, int max_map);
char					**put_dots(t_figures *lst, char **map, int max_map);
int						fill_figure(t_figures *lst, char **map, int a, int j);
int						check(t_figures *lst, char **map, int a, int j);
void					ft_create_struct_2(char **spl_b, t_figures *lst, int i);

#endif
