/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho <aghergho@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:52:21 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/06 01:41:44 by aghergho         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*
    get_next_line functions
*/
char	*str_sub(char *str, int len);
int     check_end_line(char *str);
char	*get_next_line(int fd);

/*
    end  of get_next_line functions
*/

typedef struct enemy
{
    int             x;
    int             y;
    int             direction;
    struct enemy    *next;
}   t_enemy;

typedef struct player
{
    int             x;
    int             y;
    int             direction;
    char            *img[2];
    struct player   *next;
} t_player;

typedef struct map
{
    char        **grid;
    int         player;
    int         col;
    int         exit;
    int         n_colums;
    int         n_row;
    struct map  *next;
}   t_map;

typedef struct  so_long
{
    void        *mlx;
    void        *win;
    int		    cur_moves;
    t_map	    *map;
    t_player    *player;
    // t_enemy *enemy;
}   t_slong ;


# endif
