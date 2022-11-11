/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 07:55:32 by shbi              #+#    #+#             */
/*   Updated: 2022/11/11 08:20:06 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_last_line(char **map)
{
	int	i;
	int	h;

	i = 0;
	h = map_height(map);
	while (map[h][i] && map[h][i] == '1')
	{
		i++;
		if (!map[h][i] && i > 2)
			return (1);
	}
	return (0);
}

int	check_first_col(char **map)
{
	int	i;

	i = 0;
	while (map[i] && map[i][0] == '1')
	{
		i++;
		if (!map[i])
			return (1);
	}
	return (0);
}

int	check_last_col(char **map)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(map[0]) - 1;
	while (map[i] && map[i][l] == '1')
	{
		i++;
		if (!map[i])
			return (1);
	}
	return (0);
}

void	element_start(t_info *info)
{
	info->exit = 0;
	info->coins = 0;
	info->player = 0;
}

int	check_character(char **map, t_info *info, int i, int j)
{
	element_start(info);
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				info->exit++;
			else if (map[i][j] == 'C')
				info->coins++;
			else if (map[i][j] == 'P')
				info->player++;
			else if (map[i][j] == '1' || map[i][j] == '0')
			{
				j++;
				continue ;
			}
			else
				error_map();
			j++;
		}
	}
	if (info->exit == 1 && info->coins >= 1 && info->player == 1)
		return (1);
	return (0);
}
