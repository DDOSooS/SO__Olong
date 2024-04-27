/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:11:47 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/27 01:37:48 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_number_len(int number)
{
	int	counter;

	counter = 0;
	if (!number)
		return (1);
	while (number)
	{
		number = number / 10;
		counter++;
	}
	return (counter);
}

int	ft_close_window(t_slong *game)
{
	ft_destroy_game(game);
	exit(EXIT_SUCCESS);
	return (1);
}

void	ft_free_grid(char **grid, int n_row)
{
	int	i;

	i = 0;
	if (!grid)
		return ;
	while (i < n_row)
	{
		if (grid[i])
		{
			free(grid[i]);
			grid[i] = NULL;
		}
		i++;
	}
	free(grid);
}

void	ft_destroy_game(t_slong *game)
{
	if (game->map)
	{
		ft_free_grid(game->map->grid, game->map->n_row);
		free(game->map);
	}
	if (game->player != NULL)
		free(game->player);
	if (game->mlx)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
