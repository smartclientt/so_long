/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:16:33 by shbi              #+#    #+#             */
/*   Updated: 2022/11/11 07:54:28 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_img(t_info *info, char **map)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, (ft_strlen(map[0])) * 32,
			(map_height(map) + 1) * 32, "So_long");
	info->img_wall = mlx_xpm_file_to_image(info->mlx, "./imgs/wall.xpm",
			&info->img_width, &info->img_height);
	info->img_coin = mlx_xpm_file_to_image(info->mlx, "./imgs/coin.xpm",
			&info->img_width, &info->img_height);
	info->img_player = mlx_xpm_file_to_image(info->mlx, "./imgs/player.xpm",
			&info->img_width, &info->img_height);
	info->img_space = mlx_xpm_file_to_image(info->mlx, "./imgs/space.xpm",
			&info->img_width, &info->img_height);
	info->img_exit = mlx_xpm_file_to_image(info->mlx, "./imgs/exit.xpm",
			&info->img_width, &info->img_height);
	info->index_x = 0;
	info->index_y = 0;
	info->count = 0;
	info->coins_nbr = 0;
	info->move = 0;
}

void	build_ground(t_info info)
{
	int	x;
	int	y;

	x = 0;
	while (info.map[x])
	{
		y = 0;
		while (info.map[x][y])
		{
			mlx_put_image_to_window(info.mlx, info.win,
				info.img_space, 32 * y, 32 * x);
			y++;
		}
		x++;
	}
}

void	put_img_case(char element, t_info info, int x, int y)
{
	if (element == '1')
		mlx_put_image_to_window(info.mlx, info.win,
			info.img_wall, 32 * y, 32 * x);
	else if (element == '0')
		mlx_put_image_to_window(info.mlx, info.win,
			info.img_space, 32 * y, 32 * x);
	else if (element == 'E')
		mlx_put_image_to_window(info.mlx, info.win,
			info.img_exit, 32 * y, 32 * x);
	else if (element == 'C')
		mlx_put_image_to_window(info.mlx, info.win,
			info.img_coin, 32 * y, 32 * x);
	else if (element == 'P')
		mlx_put_image_to_window(info.mlx, info.win,
			info.img_player, 32 * y, 32 * x);
}

void	build_map(t_info info)
{
	int	x;
	int	y;

	build_ground(info);
	x = 0;
	while (info.map[x])
	{
		y = 0;
		while (info.map[x][y])
		{
			put_img_case(info.map[x][y], info, x, y);
			y++;
		}
		x++;
	}
}
