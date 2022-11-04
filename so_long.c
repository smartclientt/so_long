/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:17:01 by shbi              #+#    #+#             */
/*   Updated: 2022/11/04 02:19:11 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_info info;

	if (ac == 2 && check_name_file(av[1]))
	{
		info.str_map = collect_map_element(check_name_file(av[1]));
		info.map = get_map(info.str_map);
		if (check_map(info.map))
		{
			
		}
	}
	return (0);
}
