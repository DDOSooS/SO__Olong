# ifndef SO_LONG_H
# define SO_LONG_H

typedef struct map_data
{
    char    **grid;
    int     exit_obj;
    int     player_obj;
    int     col_obj;
    int     walls;
    int     num_col;
    int     num_rows;
}   map_data;


#endif