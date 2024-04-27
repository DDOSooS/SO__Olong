/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_map_component.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:29:45 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/27 02:13:41 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_gety_component_position(char **map, int n_row, int n_col,
		char compoenent)
{
	int	i;
	int	j;

	i = 0;
	while (i < n_row)
	{
		j = 0;
		while (j < n_col)
		{
			if (map[i][j] == compoenent)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_getx_component_position(char **map, int n_row, int n_col,
		char compoenent)
{
	int	i;
	int	j;

	i = 0;
	while (i < n_row)
	{
		j = 0;
		while (j < n_col)
		{
			if (map[i][j] == compoenent)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_component(t_slong **game, char c)
{
	if (c == '1')
		return (1);
	else if (c == '0')
		return (1);
	else if (c == 'C')
	{
		(*game)->map->col = (*game)->map->col + 1;
		return (1);
	}
	else if (c == 'E')
	{
		(*game)->map->exit = (*game)->map->exit + 1;
		return (1);
	}
	else if (c == 'P')
	{
		(*game)->map->player = (*game)->map->player + 1;
		return (1);
	}
	else if (c == 'I')
		return (1);
	return (0);
}

int	ft_check_bounds(t_slong **game)
{
	if ((*game)->map->col < 1)
		return (0);
	if ((*game)->map->exit != 1)
		return (0);
	if ((*game)->map->player != 1)
		return (0);
	return (1);
}

int	ft_check_map_component(t_slong **game, int rows, int cols)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
			{
				if ((*game)->map->grid[i][j] != '1')
					return (0);
			}
			else if (!ft_check_component(game, (*game)->map->grid[i][j]))
				return (0);
		}
	}
	if (!ft_check_bounds(game))
		return (0);
	return (1);
}
