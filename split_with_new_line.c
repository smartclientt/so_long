/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_with_new_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:04:29 by shbi              #+#    #+#             */
/*   Updated: 2022/11/03 20:04:22 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_str(const char *s)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s[i])
	{
		if (is_new_line(s[i]))
			while (is_new_line(s[i]) && s[i])
				i++;
		else
		{
			while (!is_new_line(s[i]) && s[i])
				i++;
			r++;
		}
	}
	return (r);
}

int	get_len(const char *s, int *index)
{
	int	r;

	r = 0;
	while (s[*index] && !is_new_line(s[*index]))
	{
		(*index)++;
		r++;
	}
	return (r);
}

int	get_index(const char *s, int *index)
{
	while (s[*index])
	{
		if (!is_new_line(s[*index]))
			break ;
		(*index)++;
	}
	return (*index);
}

char	**spliting(char const *s, char **str, int i)
{
	int	index;
	int	point;
	int	r;
	int	j;

	index = 0;
	while (++i < count_str((char *)s))
	{
		point = get_index((char *)s, &index);
		r = get_len(s, &index);
		str[i] = (char *)malloc(sizeof(char) * (r + 1));
		if (!str[i])
		{
			j = 0;
			while (j < i && str[j])
				free(str[j++]);
			free(str);
			return (0);
		}
		str[i][r] = '\0';
		while (--r >= 0)
			str[i][r] = s[point + r];
	}
	str[i] = NULL;
	return (str);
}

char	**split_with_new_line(char const *s)
{
	char	**str;
	int		i;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * count_str(s) + 1);
	if (!str)
		return (NULL);
	i = -1;
	str = spliting(s, str, i);
	return (str);
}
