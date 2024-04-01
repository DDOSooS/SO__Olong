
#include "../includes/so_long.h"

int ft_check_extension(char *str)
{
    char *extension = ft_strchr(str, '.');
    if (!extension)
        return 0;
    if (ft_strcmp(extension, ".ber") != 0)
        return 0;
    return 1;
}

int ft_count_rows(int fd)
{
    int n_row = 0;
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        free(line);
        n_row++;
    }
    return n_row;
}

void ft_free_grid(char **grid, int n_row)
{
    int i;

    i = 0;
    if (!grid)
        return;
    while (i < n_row)
    {
        if (grid[i])
        {
            free(grid[i]);
            grid[i] = NULL;
        }
        i++;
    }
    free(grid);
}

void ft_destroy_game(t_slong *game)
{
    if (!game->map)
        return;
    if (game->map->grid)
        ft_free_grid(game->map->grid, game->map->n_row);
    free(game->map);
}

int *ft_gen_row(char *line)
{
    int *row;
    int i;
    int len;
    char *str;

    i = 0;
    str = ft_strtrim(line, "\n");
    if (! str)
        return (NULL);
    len = ft_strlen(str);
    row = malloc(sizeof(int) * len);
    if (!row)
    {
        return (free(row), NULL);
    }
    while (i < len)
    {
        row[i] = str[i] - '0';
        i++;
    }
    return (row);
}




int    ft_gen_map(t_map *map, char *map_file)
{
    int     fd;
    char    *line;
    int     i;

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

int ft_calculate_col(char *line)
{
    char    *str;
    int     col;

    str = ft_strtrim(line, "\n");
    if (! str)
        return (0);
    col = ft_strlen(str);
    free(str);
    return (col);
}

int ft_count_collums(char *map_file, int n_row)
{
    int col;
    int fd;
    char *line;
    int i;

    i = -1;
    col = 0;
    fd = open(map_file, O_RDONLY);
    if (fd == -1)
        return (0);
    while (++i < n_row)
    {
        line = get_next_line(fd);
        if (! col)
            col = ft_calculate_col(line);
        else if (col != ft_calculate_col(line))
            return(free(line), 0);
        free(line);
    }
    close(fd);
    return (col);
}

int ft_init_requirement(t_slong *game, char *map_file)
{
    int fd;

    fd = open(map_file, O_RDONLY);
    if (fd == -1 || !ft_check_extension(map_file))
        return 0;
    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return 0;
    game->map->grid = NULL;
    game->map->n_row = ft_count_rows(fd);
    if (game->map->n_row < 5)
        return (0);
    game->map->n_colums = ft_count_collums(map_file, game->map->n_row);
    if (game->map->n_colums < 3)
        return (0);
    game->map->grid = malloc(sizeof(char *) * game->map->n_row);
    if (!game->map->grid)
        return (0);
    if (! ft_gen_map(game->map, map_file))
        return (0);
    close(fd);
    return 1;
}

void var_dump(char **map, int row, int col)
{

    int i;
    int  j;

    i = 0;
    while (i < row )
    {
        j = 0;
        while (j < col)
        {
                printf("%c", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
int main(int ac, char **av)
{
    t_slong game;

    if (ac != 2)
        return 1;

    if (!ft_init_requirement(&game, av[1]))
    {
        ft_destroy_game(&game);
        return 1;
    }
    var_dump(game.map->grid, game.map->n_row, game.map->n_colums);
    
    // Other operations if needed

    ft_destroy_game(&game);

    return 0;
}
