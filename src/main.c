/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:11:51 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/27 17:40:37 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_requirement(t_slong *game, char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1 || !ft_check_extension(map_file))
		return (ft_printf("Error\npleas make sure that u have a valid file"),
			0);
	game->map = ft_new_map();
	if (!game->map)
		return (0);
	game->cur_moves = 0;
	game->map->n_row = ft_count_rows(fd);
	if (game->map->n_row < 3)
		return (0);
	game->map->n_colums = ft_count_collums(map_file, game->map->n_row);
	if (game->map->n_colums < 3)
		return (ft_printf("Error\nMAP ERROR ;(\n"), 0);
	game->map->grid = malloc(sizeof(char *) * game->map->n_row);
	if (!game->map->grid)
		return (0);
	if (!ft_gen_map(game->map, map_file))
		return (0);
	close(fd);
	return (1);
}

int	ft_check_valid_path(t_map *map, int n_rows, int n_cols)
{
	int		x_player;
	int		y_player;
	int		x_exit;
	int		y_exit;
	char	**map1;

	x_player = ft_getx_component_position(map->grid, n_rows, n_cols, 'P');
	y_player = ft_gety_component_position(map->grid, n_rows, n_cols, 'P');
	x_exit = ft_getx_component_position(map->grid, n_rows, n_cols, 'E');
	y_exit = ft_gety_component_position(map->grid, n_rows, n_cols, 'E');
	map1 = ft_init_map(map->grid, n_rows, n_cols);
	map1[x_player][y_player] = 'v';
	ft_flood_fill(&map1, x_player, y_player, map);
	if (!ft_check_map_status(&map1, x_exit, y_exit, map))
		return (0);
	return (1);
}

int	ft_validate_map(t_slong *game, char *map_file)
{
	if (!ft_check_map_component(&game, game->map->n_row, game->map->n_colums))
		return (ft_printf("Error\nmap component error ;(\n"), 0);
	if (!ft_check_valid_path(game->map, game->map->n_row, game->map->n_colums))
		return (ft_printf("Error\nthere's no Valid Path ;(\n"), 0);
	game->map->col = ft_count_collectible(game->map->grid, game->map->n_row,
			game->map->n_colums);
	ft_free_grid(game->map->grid, game->map->n_row);
	game->map->grid = malloc(sizeof(char *) * game->map->n_row);
	if (!game->map->grid)
		return (0);
	if (!ft_gen_map(game->map, map_file))
		return (0);
	game->map->col = ft_count_collectible(game->map->grid, game->map->n_row,
			game->map->n_colums);
	return (1);
}

int	ft_init_game(t_slong *game)
{
	int	width;
	int	height;

	width = game->map->n_colums * 32;
	height = game->map->n_row * 32 + 32;
	game->player = ft_gen_player(game->map->grid, game->map->n_row,
			game->map->n_colums);
	if (!game->player)
		return (ft_destroy_game(game), 0);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width, height, "S0__0Long");
	mlx_hook(game->win, 2, 1, &ft_move_player, game);
	mlx_hook(game->win, 17, 32, &ft_close_window, game);
	mlx_loop_hook(game->mlx, ft_animate_component, game);
	mlx_loop(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	return (1);
}

int	main(int ac, char **av)
{
	t_slong	game;

	if (ac != 2)
		return (1);
	game.player = NULL;
	game.map = NULL;
	game.cur_moves = 0;
	game.mlx = NULL;
	if (!ft_init_requirement(&game, av[1]))
		return (ft_destroy_game(&game), 1);
	if (!ft_validate_map(&game, av[1]))
		return (ft_destroy_game(&game), 1);
	if (!ft_init_game(&game))
		return (1);
	return (0);
}
