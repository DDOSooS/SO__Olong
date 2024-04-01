/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho <aghergho@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:55:01 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/01 10:56:18 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

char	*str_sub(char *str, int len)
{
	char	*s;
	int		i;

	if (!len)
		len++;
	s = (char *) malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (i < len && str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int	check_end_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	if (str[0] == '\n')
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}