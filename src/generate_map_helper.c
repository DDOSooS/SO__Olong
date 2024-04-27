/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:38:15 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/27 01:05:55 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_rows(int fd)
{
	int		n_row;
	char	*line;

	n_row = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		n_row++;
		line = get_next_line(fd);
	}
	return (n_row);
}

int	ft_calculate_col(char *line)
{
	char	*str;
	int		col;

	str = ft_strtrim(line, "\n");
	if (!str)
		return (0);
	col = ft_strlen(str);
	free(str);
	return (col);
}

int	ft_count_collums(char *map_file, int n_row)
{
	int		col;
	int		fd;
	char	*line;
	int		i;

	i = -1;
	col = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (++i < n_row)
	{
		line = get_next_line(fd);
		if (!col)
			col = ft_calculate_col(line);
		else if (col != ft_calculate_col(line))
			return (free(line), 0);
		free(line);
	}
	close(fd);
	return (col);
}
