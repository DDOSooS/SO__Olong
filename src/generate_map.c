/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:25:22 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/27 01:46:13 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_extension(char *str)
{
	char	*extension;

	extension = ft_strchr(str, '.');
	if (!extension)
		return (0);
	if (ft_strcmp(extension, ".ber") != 0)
		return (0);
	return (1);
}

void	ft_set_enemy_img(t_map **map)
{
	(*map)->enemy_img[0] = "imgs/enemy/e1.xpm";
	(*map)->enemy_img[1] = "imgs/enemy/e2.xpm";
	(*map)->enemy_img[2] = "imgs/enemy/e3.xpm";
	(*map)->enemy_img[3] = "imgs/enemy/e4.xpm";
	(*map)->enemy_img[4] = "imgs/enemy/e5.xpm";
	(*map)->enemy_img[5] = "imgs/enemy/e6.xpm";
	(*map)->enemy_img[6] = "imgs/enemy/e7.xpm";
	(*map)->enemy_img[7] = "imgs/enemy/e8.xpm";
	(*map)->enemy_img[8] = "imgs/enemy/e9.xpm";
	(*map)->enemy_img[9] = "imgs/enemy/e10.xpm";
	(*map)->enemy_img[10] = "imgs/enemy/e11.xpm";
}

void	ft_set_col_img(t_map **map)
{
	(*map)->coll_img[0] = "imgs/col/k1.xpm";
	(*map)->coll_img[1] = "imgs/col/k2.xpm";
	(*map)->coll_img[2] = "imgs/col/k3.xpm";
	(*map)->coll_img[3] = "imgs/col/k4.xpm";
	(*map)->coll_img[4] = "imgs/col/k5 .xpm";
	(*map)->coll_img[5] = "imgs/col/k6.xpm";
	(*map)->coll_img[6] = "imgs/col/k7.xpm";
	(*map)->coll_img[7] = "imgs/col/k8.xpm";
}

void	ft_set_number_img(t_map **map)
{
	(*map)->number_img[0] = "imgs/numbers/0.xpm";
	(*map)->number_img[1] = "imgs/numbers/1.xpm";
	(*map)->number_img[2] = "imgs/numbers/2.xpm";
	(*map)->number_img[3] = "imgs/numbers/3.xpm";
	(*map)->number_img[4] = "imgs/numbers/4.xpm";
	(*map)->number_img[5] = "imgs/numbers/5.xpm";
	(*map)->number_img[6] = "imgs/numbers/6.xpm";
	(*map)->number_img[7] = "imgs/numbers/7.xpm";
	(*map)->number_img[8] = "imgs/numbers/8.xpm";
	(*map)->number_img[9] = "imgs/numbers/9.xpm";
}

t_map	*ft_new_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->n_row = 0;
	map->n_colums = 0;
	map->player = 0;
	map->col = 0;
	map->exit = 0;
	map->grid = NULL;
	map->wall_img[0] = "imgs/walls/w1.xpm";
	map->wall_img[1] = "imgs/walls/w2.xpm";
	map->exit_img[0] = "imgs/exit/ex1.xpm";
	map->exit_img[1] = "imgs/exit/ex2.xpm";
	ft_set_enemy_img(&map);
	ft_set_col_img(&map);
	ft_set_number_img(&map);
	return (map);
}
