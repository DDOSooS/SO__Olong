/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:14:19 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/27 01:44:43 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_player	*ft_gen_player(char **grid, int n_rows, int n_col)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = ft_getx_component_position(grid, n_rows, n_col, 'P');
	player->y = ft_gety_component_position(grid, n_rows, n_col, 'P');
	player->img[0] = "imgs/player/p1.xpm";
	player->img[1] = "imgs/player/p2.xpm";
	player->img[2] = "imgs/player/p3.xpm";
	player->img[3] = "imgs/player/p4.xpm";
	player->img[4] = "imgs/player/p5.xpm";
	player->img[5] = "imgs/player/p6.xpm";
	player->img[6] = "imgs/player/p7.xpm";
	player->img[7] = "imgs/player/p8.xpm";
	player->img[8] = "imgs/player/p9.xpm";
	player->img[9] = "imgs/player/p10.xpm";
	player->img[10] = "imgs/player/p11.xpm";
	player->img[11] = "imgs/player/p12.xpm";
	player->img[12] = "imgs/player/p13.xpm";
	player->img[13] = "imgs/player/p14.xpm";
	player->flag = 0;
	return (player);
}

int	ft_gen_map(t_map *map, char *map_file)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (++i < map->n_row)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		map->grid[i] = ft_strtrim(line, "\n");
		if (!map->grid[i])
			return (free(line), 0);
		free(line);
	}
	close(fd);
	return (1);
}
