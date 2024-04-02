/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho <aghergho@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:52:21 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/02 10:04:14 by aghergho         ###   ########.fr       */
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
    int             pos;
    int             direction;
    struct enemy    *next;
}   t_enemy;


typedef struct map
{
    char         **grid;
    int         player;
    int         col;
    int         exit;
    int         n_colums;
    int         n_row;
    struct map  *next;
}   t_map;

typedef struct  so_long
{
    t_map	*map;
    int		cur_moves;
    // t_enemy *enemy;
}   t_slong ;


# endif
