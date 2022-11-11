/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:06:17 by shbi              #+#    #+#             */
/*   Updated: 2022/11/11 02:25:57 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_new_line(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i - 1);
}

void	get_coins_nbr(t_info *info)
{
	int	x;
	int	y;

	x = 0;
	while (info->map[x])
	{
		y = 0;
		while (info->map[x][y])
		{
			if (info->map[x][y] == 'C')
				info->coins_nbr++;
			y++;
		}
		x++;
	}
}
