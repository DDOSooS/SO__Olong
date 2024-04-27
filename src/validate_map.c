/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:46:46 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/27 02:11:58 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_init_map(char **grid, int n_row, int n_col)
{
	int	i;
	int	j;

	i = 0;
	while (i < n_row)
	{
		j = 0;
		while (j < n_col)
		{
			if (grid[i][j] == 'P')
				grid[i][j] = '0';
			else if (grid[i][j] == 'E')
				grid[i][j] = '1';
			j++;
		}
		i++;
	}
	return (grid);
}

int	ft_count_collectible(char **grid, int r, int c)
{
	int	counter;
	int	i;
	int	j;

	counter = 0;
	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			if (grid[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	ft_check_map_status(char ***grid, int x, int y, t_map *map)
{
	int	collectible;

	collectible = ft_count_collectible(*grid, map->n_row, map->n_colums);
	if (collectible != 0)
		return (0);
	if ((*grid)[x][y + 1] == 'v' || (*grid)[x][y - 1] == 'v' || (*grid)[x
		+ 1][y] == 'v' || (*grid)[x - 1][y] == 'v')
		return (1);
	return (0);
}

void	dfs(char ***grid, int i, int y, t_map *map)
{
	if (i < 0 || i >= map->n_row || y < 0 || y >= map->n_colums)
		return ;
	if ((*grid)[i][y] == '1' || (*grid)[i][y] == 'I')
		return ;
	if ((*grid)[i][y] != 'v')
		(*grid)[i][y] = 'v';
	else
		return ;
	dfs(grid, i, y + 1, map);
	dfs(grid, i, y - 1, map);
	dfs(grid, i + 1, y, map);
	dfs(grid, i - 1, y, map);
}

void	ft_flood_fill(char ***grid, int i, int y, t_map *map)
{
	dfs(grid, i, y + 1, map);
	dfs(grid, i, y - 1, map);
	dfs(grid, i + 1, y, map);
	dfs(grid, i - 1, y, map);
}
