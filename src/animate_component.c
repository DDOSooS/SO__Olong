/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_component.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:19:41 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/27 02:12:39 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_update_player_img(t_slong **game)
{
	int			flag;
	static int	index = 0;

	flag = 1;
	while (1)
	{
		(*game)->map->d_player_img = (*game)->player->img[index];
		if (flag % 5000000 == 0)
		{
			index++;
			break ;
		}
		if (index == 14)
			index = 0;
		flag++;
	}
}

void	ft_update_enemy_img(t_slong **game)
{
	int			flag;
	static int	index = 0;

	flag = 1;
	while (1)
	{
		(*game)->map->d_enemy_img = (*game)->map->enemy_img[index];
		if (flag % 50000000 == 0)
		{
			index++;
			break ;
		}
		if (index == 11)
			index = 0;
		flag++;
	}
}

int	ft_update_col_img(t_slong **game)
{
	int			flag;
	static int	index = 0;

	flag = 1;
	while (1)
	{
		(*game)->map->d_col_img = (*game)->map->coll_img[index];
		if (flag % 500000 == 0)
		{
			index++;
			break ;
		}
		if (index == 8)
			index = 0;
		flag++;
	}
	return (1);
}

int	ft_update_exit_img(t_slong **game)
{
	int			flag;
	static int	index = 0;

	flag = 1;
	while (1)
	{
		(*game)->map->d_exit_img = (*game)->map->exit_img[index];
		if (flag % 5010000 == 0)
		{
			index++;
			break ;
		}
		if (index == 2)
			index = 0;
		flag++;
	}
	return (1);
}

int	ft_animate_component(t_slong *game)
{
	ft_update_player_img(&game);
	ft_update_exit_img(&game);
	ft_update_enemy_img(&game);
	ft_update_col_img(&game);
	ft_update_number(&game);
	if (!ft_gen_window(game))
	{
		ft_printf("error\n");
		ft_destroy_game(game);
		exit(0);
	}
	return (1);
}
