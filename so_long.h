/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:17:03 by shbi              #+#    #+#             */
/*   Updated: 2022/11/04 01:25:28 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

typedef struct s_info
{
	char	*str_map;
	char	**map;
	int		exit;
	int		coins;
	int		player;
}	t_info;

//libft functions 
int		ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *f_line, char *buffer);

// split with new line
int		count_str(const char *s);
int		get_len(const char *s, int *index);
int		get_index(const char *s, int *index);
char	**spliting(char const *s, char **str, int i);
char	**split_with_new_line(char const *s);

// tools
int		is_new_line(char c);
int		map_height(char **map);

//check file
int		comp_name(char *name);
int		check_name_file(char *av);

//check map
int		check_map(char **map);
char	*collect_map_element(int fd);
char	**get_map(char *str_map);
int		check_rectangle(char **map);
int		check_first_line(char **map);
int		check_last_line(char **map);
int		check_first_col(char **map);
int		check_last_col(char **map);
int		check_character(char **map);

//Error case
void	error_name_file(void);
void	error_map(void);



#endif