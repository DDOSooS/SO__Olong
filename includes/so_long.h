/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:52:21 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/27 02:05:55 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
#include "../minilibx-linux/mlx.h"


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


#define KEY_LEFT 65361
#define KEY_UP 65362
#define KEY_RIGHT 65363
#define KEY_DOWN 65364
#define ESC 65307
typedef struct player
{
    int             x;
    int             y;
    int             flag;
    char            *img[14];
} t_player;

typedef struct map
{
    char        **grid;
    int         player; 
    int         col;
    int         exit;
    int         n_colums;
    int         n_row;
    char        *wall_img[2];
    char        *enemy_img[11];
    char        *coll_img[8];
    char        *exit_img[2];
    char        *number_img[10];
    char        *d_enemy_img;    
    char        *d_col_img;    
    char        *d_exit_img;
    char        *d_player_img;
}   t_map;

typedef struct  so_long
{
    void        *mlx;
    void        *win;
    int		    cur_moves;
    t_map	    *map;
    t_player    *player;
}   t_slong ;

/*
    get_next_line functions
*/
int	ft_printf(const char *format, ...);
char	*str_sub(char *str, int len);
int     check_end_line(char *str);
char	*get_next_line(int fd);

/*
    end  of get_next_line functions
*/
t_map   *ft_new_map();
t_player *ft_gen_player(char **grid, int n_rows, int n_col);
int	ft_gen_window(t_slong *game);
int    ft_gen_map(t_map *map, char *map_file);
int ft_check_map_component(t_slong **game, int rows, int cols);
int ft_gety_component_position(char **map, int n_row, int n_col, char compoenent);
int ft_getx_component_position(char **map, int n_row, int n_col, char compoenent);
int ft_check_extension(char *str);
int ft_count_rows(int fd);
int ft_calculate_col(char *line);
int ft_count_collums(char *map_file, int n_row);
void ft_free_grid(char **grid, int n_row);
int ft_check_map_component(t_slong **game, int rows, int cols);
char **ft_init_map(char **grid, int n_row, int n_col);
void ft_flood_fill(char ***grid, int i, int y, t_map *map);
char **ft_init_map(char **grid, int n_row, int n_col);
int ft_count_collectible(char **grid, int r, int c);
int	ft_move_player(int keycode, t_slong *game);
int ft_swap_right(t_slong *game, int x, int y);
int ft_swap_left(t_slong *game, int x, int y);
int ft_swap_down(t_slong *game, int x, int y);
int ft_swap_up(t_slong *game, int x, int y);
int    ft_update_number(t_slong **game);
int ft_close_window( t_slong *game);
void ft_destroy_game(t_slong *game);
int ft_count_number_len(int number);
int ft_animate_component(t_slong *game);
int ft_get_image_id(char component, int i, int j, t_map *map);
char *ft_get_img_path(t_slong *game, int i, int j);
int ft_check_map_status(char ***grid, int x, int y, t_map *map);
char	*ft_get_wall(t_map *map, int i, int j);


# endif
