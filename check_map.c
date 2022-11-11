/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:11:52 by shbi              #+#    #+#             */
/*   Updated: 2022/11/11 08:19:47 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*collect_map_element(int fd)
{
	t_info	info;
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	if (!line)
		error_map();
	info.str_map = ft_strdup("");
	while (line)
	{
		tmp = info.str_map;
		info.str_map = ft_strjoin(info.str_map, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	return (info.str_map);
}

char	**get_map(char *str_map)
{
	return (split_with_new_line(str_map));
}

int	check_rectangle(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1] && ft_strlen(map[i]) == ft_strlen(map[i + 1]))
	{
		i++;
		if (!map[i + 1] && i > 1)
			return (i + 1);
	}
	return (0);
}

int	check_map(char **map, t_info *info)
{
	if (!*map)
		error_map();
	else if (!check_rectangle(map))
		error_map();
	else if (!check_first_line(map) || !check_last_line(map)
		|| !check_first_col(map) || !check_last_col(map)
		|| !check_character(map, info, -1, 0))
		error_map();
	else
		return (1);
	return (0);
}

int	check_first_line(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] && map[0][i] == '1')
	{
		i++;
		if (!map[0][i] && i > 2)
			return (1);
	}
	return (0);
}
