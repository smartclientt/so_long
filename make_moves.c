/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:16:56 by shbi              #+#    #+#             */
/*   Updated: 2022/11/11 07:50:29 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (info->map[y][x] == 'P')
			{
				info->index_y = y;
				info->index_x = x;
				break ;
			}
			x++;
		}
		if (info->map[y][x] == 'P')
			break ;
		y++;
	}
}

void	move_right(t_info *info)
{
	if (info->map[info->index_y][info->index_x + 1] == '0')
	{
		ft_printf("move = %d\n", ++info->move);
		info->map[info->index_y][info->index_x] = '0';
		info->map[info->index_y][info->index_x + 1] = 'P';
		info->index_x++;
		mlx_clear_window(info->mlx, info->win);
		build_map(*info);
	}
	else if (info->map[info->index_y][info->index_x + 1] == 'C')
	{
		ft_printf("move = %d\n", ++info->move);
		info->map[info->index_y][info->index_x] = '0';
		info->map[info->index_y][info->index_x + 1] = 'P';
		info->index_x++;
		info->count++;
		mlx_clear_window(info->mlx, info->win);
		build_map(*info);
	}
	else if (info->map[info->index_y][info->index_x + 1] == 'E'
				&& info->coins_nbr != info->count)
		return ;
	else if (info->map[info->index_y][info->index_x + 1] == 'E'
				&& info->coins_nbr == info->count)
		end_game(info);
}

void	move_left(t_info *info)
{
	if (info->map[info->index_y][info->index_x - 1] == '0')
	{
		ft_printf("move = %d\n", ++info->move);
		info->map[info->index_y][info->index_x] = '0';
		info->map[info->index_y][info->index_x - 1] = 'P';
		info->index_x--;
		mlx_clear_window(info->mlx, info->win);
		build_map(*info);
	}
	else if (info->map[info->index_y][info->index_x - 1] == 'C')
	{
		ft_printf("move = %d\n", ++info->move);
		info->map[info->index_y][info->index_x] = '0';
		info->map[info->index_y][info->index_x - 1] = 'P';
		info->index_x--;
		info->count++;
		mlx_clear_window(info->mlx, info->win);
		build_map(*info);
	}
	else if (info->map[info->index_y][info->index_x - 1] == 'E'
				&& info->coins_nbr != info->count)
		return ;
	else if (info->map[info->index_y][info->index_x - 1] == 'E'
				&& info->coins_nbr == info->count)
		end_game(info);
}

void	move_up(t_info *info)
{
	if (info->map[info->index_y - 1][info->index_x] == '0')
	{
		info->map[info->index_y][info->index_x] = '0';
		info->map[info->index_y - 1][info->index_x] = 'P';
		info->index_y--;
		mlx_clear_window(info->mlx, info->win);
		build_map(*info);
	}
	else if (info->map[info->index_y - 1][info->index_x] == 'C')
	{
		ft_printf("move = %d\n", ++info->move);
		info->map[info->index_y][info->index_x] = '0';
		info->map[info->index_y - 1][info->index_x] = 'P';
		info->index_y--;
		info->count++;
		mlx_clear_window(info->mlx, info->win);
		build_map(*info);
	}
	else if (info->map[info->index_y - 1][info->index_x] == 'E'
				&& info->coins_nbr != info->count)
		return ;
	else if (info->map[info->index_y - 1][info->index_x] == 'E'
				&& info->coins_nbr == info->count)
		end_game(info);
}

void	move_down(t_info *info)
{
	if (info->map[info->index_y + 1][info->index_x] == '0')
	{
		ft_printf("move = %d\n", ++info->move);
		info->map[info->index_y][info->index_x] = '0';
		info->map[info->index_y + 1][info->index_x] = 'P';
		info->index_y++;
		mlx_clear_window(info->mlx, info->win);
		build_map(*info);
	}
	else if (info->map[info->index_y + 1][info->index_x] == 'C')
	{
		ft_printf("move = %d\n", ++info->move);
		info->map[info->index_y][info->index_x] = '0';
		info->map[info->index_y + 1][info->index_x] = 'P';
		info->index_y++;
		info->count++;
		mlx_clear_window(info->mlx, info->win);
		build_map(*info);
	}
	else if (info->map[info->index_y + 1][info->index_x] == 'E'
				&& info->coins_nbr != info->count)
		return ;
	else if (info->map[info->index_y + 1][info->index_x] == 'E'
				&& info->coins_nbr == info->count)
		end_game(info);
}
