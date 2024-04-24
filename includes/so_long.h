/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho < aghergho@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:52:21 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/24 16:54:57 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include "../libft/libft.h"
# include <fcntl.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


#define KEY_LEFT 65361
#define KEY_UP 65362
#define KEY_RIGHT 65363
#define KEY_DOWN 65364
#define ESC 65307
/*
    get_next_line functions
*/
char	*str_sub(char *str, int len);
int     check_end_line(char *str);
char	*get_next_line(int fd);

/*
    end  of get_next_line functions
*/


typedef struct player
{
    int             x;//4
    int             y;//4
    int             flag; //4
    char            *img[14]; //2 * 8 =  32
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
}   t_map;

typedef struct  so_long
{
    void        *mlx;
    void        *win;
    int		    cur_moves;
    t_map	    *map;
    t_player    *player;
}   t_slong ;


# endif
