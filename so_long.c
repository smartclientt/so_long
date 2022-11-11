/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:17:01 by shbi              #+#    #+#             */
/*   Updated: 2022/11/11 08:20:52 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(t_info *info)
{
	(void) info;
	exit(0);
	return (0);
}

int	key_hook(int key_code, t_info *info)
{
	info->key = key_code;
	if (key_code == 2)
		move_right(info);
	if (key_code == 0)
		move_left(info);
	if (key_code == 13)
		move_up(info);
	if (key_code == 1)
		move_down(info);
	else if (key_code == 53)
		exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 2 && check_name_file(av[1]))
	{
		info.str_map = collect_map_element(check_name_file(av[1]));
		info.map = get_map(info.str_map);
		if (check_map(info.map, &info))
		{
			initial_img(&info, info.map);
			build_map(info);
			get_player_position(&info);
			get_coins_nbr(&info);
			mlx_hook(info.win, 17, 0, exit_hook, &info);
			mlx_hook(info.win, 2, 0, key_hook, &info);
			mlx_loop(info.mlx);
		}
	}
	return (0);
}
