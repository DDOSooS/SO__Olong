/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:17:39 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/27 01:47:33 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_update_number(t_slong **game)
{
	int		len;
	void	*img;
	int		y;
	int		n;

	y = (((*game)->map->n_colums) * 32) / 2;
	n = (*game)->cur_moves;
	len = ft_count_number_len((*game)->cur_moves);
	while (len-- > 0)
	{
		img = mlx_xpm_file_to_image((*game)->mlx, (*game)->map->number_img[n
				% 10], &(int){32}, &(int){32});
		if (!img)
			return (ft_destroy_game(*game), exit(EXIT_FAILURE), 0);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, img, y,
			((*game)->map->n_row) * 32);
		mlx_destroy_image((*game)->mlx, img);
		n = n / 10;
		y = y - 32;
	}
	return (1);
}

int	ft_swap_up(t_slong *game, int x, int y)
{
	char	tmp;

	tmp = game->map->grid[x][y];
	if (game->map->grid[x - 1][y] == 'C')
	{
		game->map->col = game->map->col - 1;
		game->map->grid[x][y] = '0';
	}
	else
		game->map->grid[x][y] = game->map->grid[x - 1][y];
	game->map->grid[x - 1][y] = tmp;
	game->player->x = x - 1;
	if (!ft_gen_window(game))
		return (0);
	return (1);
}

int	ft_swap_down(t_slong *game, int x, int y)
{
	char	tmp;

	tmp = game->map->grid[x][y];
	if (game->map->grid[x + 1][y] == 'C')
	{
		game->map->col = game->map->col - 1;
		game->map->grid[x][y] = '0';
	}
	else
		game->map->grid[x][y] = game->map->grid[x + 1][y];
	game->map->grid[x + 1][y] = tmp;
	game->player->x = x + 1;
	if (!ft_gen_window(game))
		return (0);
	return (1);
}

int	ft_swap_left(t_slong *game, int x, int y)
{
	char	tmp;

	tmp = game->map->grid[x][y];
	if (game->map->grid[x][y - 1] == 'C')
	{
		game->map->col = game->map->col - 1;
		game->map->grid[x][y] = '0';
	}
	else
		game->map->grid[x][y] = game->map->grid[x][y - 1];
	game->map->grid[x][y - 1] = tmp;
	game->player->y = y - 1;
	if (!ft_gen_window(game))
		return (0);
	return (1);
}

int	ft_swap_right(t_slong *game, int x, int y)
{
	char	tmp;

	tmp = game->map->grid[x][y];
	if (game->map->grid[x][y + 1] == 'C')
	{
		game->map->col = game->map->col - 1;
		game->map->grid[x][y] = '0';
	}
	else
		game->map->grid[x][y] = game->map->grid[x][y + 1];
	game->map->grid[x][y + 1] = tmp;
	game->player->y = y + 1;
	if (!ft_gen_window(game))
		return (0);
	return (1);
}
