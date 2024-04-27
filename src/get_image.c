/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:40:12 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/27 02:00:24 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_get_absolute_component(t_map *map, int id, int i, int j)
{
	if (id == 0)
		return ("imgs/walls/tl.xpm");
	else if (id == 1)
		return ("imgs/walls/tr.xpm");
	else if (id == 2)
		return ("imgs/walls/t.xpm");
	else if (id == 3)
		return ("imgs/walls/bl.xpm");
	else if (id == 4)
		return ("imgs/walls/br.xpm");
	else if (id == 5)
		return ("imgs/walls/b.xpm");
	else if (id == 6)
		return ("imgs/walls/l.xpm");
	else if (id == 7)
		return ("imgs/walls/r.xpm");
	else if (id == 11)
		return ("imgs/walls/0.xpm");
	return (ft_get_wall(map, i, j));
}

char	*ft_get_image_name(t_slong game, int img_id, int i, int j)
{
	char	*img_name;

	img_name = NULL;
	if ((img_id >= 0 && img_id <= 7) || img_id == 11 || img_id == 12)
		img_name = ft_get_absolute_component(game.map, img_id, i, j);
	else if (img_id == 8)
		img_name = game.map->d_player_img;
	else if (img_id == 9)
		img_name = game.map->d_col_img;
	else if (img_id == 10)
		img_name = game.map->d_exit_img;
	else if (img_id == 13)
		img_name = game.map->d_enemy_img;
	return (img_name);
}

char	*ft_get_img_path(t_slong *game, int i, int j)
{
	char	*img_path;
	int		img_id;

	img_id = ft_get_image_id(game->map->grid[i][j], i, j, game->map);
	img_path = ft_get_image_name(*game, img_id, i, j);
	if (!img_path)
		return (NULL);
	return (img_path);
}

int	ft_get_image_id_helper(char compenent)
{
	if (compenent == '0')
		return (11);
	else if (compenent == '1')
		return (12);
	return (13);
}

int	ft_get_image_id(char component, int i, int j, t_map *map)
{
	if (i == 0 && j == 0)
		return (0);
	else if (i == 0 && j == map->n_colums - 1)
		return (1);
	else if (i == 0)
		return (2);
	else if (i == map->n_row - 1 && j == 0)
		return (3);
	else if (i == map->n_row - 1 && j == map->n_colums - 1)
		return (4);
	else if (i == map->n_row - 1)
		return (5);
	else if (j == 0)
		return (6);
	else if (j == map->n_colums - 1)
		return (7);
	else if (component == 'P')
		return (8);
	else if (component == 'C')
		return (9);
	else if (component == 'E')
		return (10);
	return (ft_get_image_id_helper(component));
}
