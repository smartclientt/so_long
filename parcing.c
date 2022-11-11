/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:33:41 by shbi              #+#    #+#             */
/*   Updated: 2022/11/11 07:59:47 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	comp_name(char *name)
{
	int	l;

	l = ft_strlen(name);
	if (l < 5)
		error_name_file();
	else
	{
		if (ft_strncmp(".ber", name + (l - 4)) == 1)
			error_name_file();
	}
	return (1);
}

int	check_name_file(char *name)
{
	int	fd;

	if (comp_name(name) == 1)
	{
		fd = open (name, O_RDONLY);
		if (fd == -1)
			error_name_file();
		return (fd);
	}
	return (1);
}
