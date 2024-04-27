/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:16:36 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/27 00:18:22 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_move_up(t_slong *game)
{
	if (game->map->grid[game->player->x - 1][game->player->y] == '1'
		|| (game->map->grid[game->player->x - 1][game->player->y] == 'E'
			&& game->map->col))
		return (1);
	else if (game->map->grid[game->player->x - 1][game->player->y] == 'E'
		&& !game->map->col)
	{
		ft_destroy_game(game);
		exit(0);
	}
	else if (game->map->grid[game->player->x - 1][game->player->y] == 'I')
	{
		ft_destroy_game(game);
		exit(0);
	}
	else
	{
		game->cur_moves++;
		return (ft_swap_up(game, game->player->x, game->player->y), 1);
	}
	return (1);
}

int	ft_move_down(t_slong *game)
{
	if (game->map->grid[game->player->x + 1][game->player->y] == '1'
		|| (game->map->grid[game->player->x + 1][game->player->y] == 'E'
			&& game->map->col))
		return (1);
	else if (game->map->grid[game->player->x + 1][game->player->y] == 'E'
		&& !game->map->col)
	{
		ft_destroy_game(game);
		exit(0);
	}
	else if (game->map->grid[game->player->x + 1][game->player->y] == 'I')
	{
		ft_destroy_game(game);
		exit(0);
	}
	else
	{
		game->cur_moves++;
		return (ft_swap_down(game, game->player->x, game->player->y), 1);
	}
	return (1);
}

int	ft_move_left(t_slong *game)
{
	if ((game)->map->grid[(game)->player->x][(game)->player->y - 1] == '1'
		|| ((game)->map->grid[(game)->player->x][(game)->player->y - 1] == 'E'
			&& (game)->map->col))
		return (1);
	else if ((game)->map->grid[(game)->player->x][(game)->player->y - 1] == 'E'
		&& !(game)->map->col)
	{
		ft_destroy_game(game);
		exit(0);
	}
	else if ((game)->map->grid[(game)->player->x][(game)->player->y - 1] == 'I')
	{
		ft_destroy_game(game);
		exit(0);
	}
	else
	{
		game->cur_moves++;
		return (ft_swap_left(game, game->player->x, game->player->y), 1);
	}
	return (1);
}

int	ft_move_right(t_slong *game)
{
	if ((game)->map->grid[(game)->player->x][(game)->player->y + 1] == '1'
		|| ((game)->map->grid[(game)->player->x][(game)->player->y + 1] == 'E'
			&& (game)->map->col))
		return (1);
	else if ((game)->map->grid[(game)->player->x][(game)->player->y + 1] == 'E'
		&& !(game)->map->col)
	{
		ft_destroy_game(game);
		exit(0);
	}
	else if ((game)->map->grid[(game)->player->x][(game)->player->y + 1] == 'I')
	{
		ft_destroy_game(game);
		exit(0);
	}
	else
	{
		game->cur_moves++;
		return (ft_swap_right(game, (game)->player->x, (game)->player->y), 1);
	}
	return (1);
}

int	ft_move_player(int keycode, t_slong *game)
{
	if (keycode == ESC)
	{
		ft_destroy_game(game);
		exit(0);
	}
	else if (keycode == KEY_UP)
		ft_move_up(game);
	else if (keycode == KEY_DOWN)
		ft_move_down(game);
	else if (keycode == KEY_LEFT)
		ft_move_left(game);
	else if (keycode == KEY_RIGHT)
		ft_move_right(game);
	return (0);
}
