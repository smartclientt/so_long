/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:17:03 by shbi              #+#    #+#             */
/*   Updated: 2022/11/11 08:19:21 by shbi             ###   ########.fr       */
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
# include "ft_printf/ft_printf.h"

typedef struct s_info
{
	char	*str_map;
	char	**map;
	int		exit;
	int		coins;
	int		player;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_space;
	void	*img_player;
	void	*img_coin;
	void	*img_exit;
	char	*path;
	int		img_width;
	int		img_height;
	int		key;
	int		index_x;
	int		index_y;
	int		coins_nbr;
	int		count;
	int		move;
}	t_info;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

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
void	get_coins_nbr(t_info *info);

//check file
int		comp_name(char *name);
int		check_name_file(char *av);

//check map
int		check_map(char **map, t_info *info);
char	*collect_map_element(int fd);
char	**get_map(char *str_map);
int		check_rectangle(char **map);
int		check_first_line(char **map);
int		check_last_line(char **map);
int		check_first_col(char **map);
int		check_last_col(char **map);
int		check_character(char **map, t_info *info, int i, int j);
void	element_start(t_info *info);

// build map
void	initial_img(t_info *info, char **map);
void	build_ground(t_info info);
void	put_img_case(char element, t_info info, int x, int y);
void	build_map(t_info info);

// end of game
void	end_game(t_info *info);

// make player move
void	get_player_position(t_info *info);
void	move_right(t_info *info);
void	move_left(t_info *info);
void	move_up(t_info *info);
void	move_down(t_info *info);

//Error case
void	error_name_file(void);
void	error_map(void);

#endif