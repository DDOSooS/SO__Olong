/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:24:23 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/27 17:36:21 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_get_wall(t_map *map, int i, int j)
{
	char	*img;

	if (j <= map->n_colums / 2)
	{
		if (i < map->n_row / 2)
			img = map->wall_img[0];
		else
			img = map->wall_img[1];
	}
	else
	{
		if (i < map->n_row / 2)
			img = map->wall_img[1];
		else
			img = map->wall_img[0];
	}
	return (img);
}

int	ft_gen_window(t_slong *game)
{
	int		i;
	int		j;
	void	*img;
	char	*path;

	i = -1;
	while (++i < game->map->n_row)
	{
		j = -1;
		while (++j < game->map->n_colums)
		{
			path = ft_get_img_path(game, i, j);
			if (!path)
				return (ft_destroy_game(game), 0);
			img = mlx_xpm_file_to_image(game->mlx, path, &(int){32},
					&(int){32});
			if (img == NULL)
				return (ft_printf("Error\nimages aren't valid"),
					ft_destroy_game(game), exit(EXIT_FAILURE), 0);
			mlx_put_image_to_window(game->mlx, game->win, img, j * 32, i * 32);
			mlx_destroy_image(game->mlx, img);
		}
	}
	return (1);
}
