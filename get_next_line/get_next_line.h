/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:28:12 by shbi              #+#    #+#             */
/*   Updated: 2022/11/03 18:24:13 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../so_long.h"

char	*ft_fre(char **s);
char	*get_line(char **f_line);
char	*get_first_line(int fd, char **f_line);
char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
char	*ft_substr(char *f_line, int start, int len);

#endif