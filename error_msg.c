/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:39:04 by shbi              #+#    #+#             */
/*   Updated: 2022/11/01 23:10:17 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_name_file(void)
{
	ft_putstr_fd("Error\nCheck ur file name\n", 2);
	exit(1);
}

void	error_map(void)
{
	ft_putstr_fd("Error\nCheck ur map\n", 2);
	exit(1);
}
