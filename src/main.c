
#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
void var_dump(char **map, int row, int col);

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

    while ((line = get_next_line(fd)) != NULL)
    {
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

t_map   *ft_new_map()
{
    t_map *map;

    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->n_row = 0;
    map->n_colums = 0;
    map->player = 0;
    map->col = 0;
    map->exit = 0;
    map->grid = NULL;
    return (map);
}

int ft_init_requirement(t_slong *game, char *map_file)
{
    int fd;

    fd = open(map_file, O_RDONLY);
    if (fd == -1 || !ft_check_extension(map_file))
        return 0;
    game->map = ft_new_map();
    if (!game->map)
        return 0;
    game->cur_moves = 0;
    game->map->n_row = ft_count_rows(fd);
    if (game->map->n_row < 3)
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

/*
    ===> validate map
*/

/*
    flood fill algorithm
*/

int ft_getx_component_position(char **map, int n_row, int n_col, char compoenent)
{
    int     i;
    int     j;

    i = 0;
    while (i < n_row)
    {
        j = 0;
        while (j < n_col)
        {
            if (map[i][j] == compoenent)
                return (i);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_gety_component_position(char **map, int n_row, int n_col, char compoenent)
{
    int     i;
    int     j;

    i = 0;
    while (i < n_row)
    {
        j = 0;
        while (j < n_col)
        {
            if (map[i][j] == compoenent)
                return (j);
            j++;
        }
        i++;
    }
    return (0);
}

char **ft_init_map(char **grid, int n_row, int n_col)
{
    int i = 0;
    while (i < n_row) {
        int j = 0;
        while (j < n_col) {
            if (grid[i][j] == 'P')
                grid[i][j] = '0';
            else if (grid[i][j] == 'E')
                grid[i][j] = '1';
            j++;
        }
        i++;
    }
    return grid;
}

void dfs(char ***grid, int i, int y, t_map *map)
{
    if (i < 0 || i >= map->n_row || y < 0 || y >= map->n_colums)
        return;
    if ((*grid)[i][y] == '1')
        return;
    if ((*grid)[i][y] != 'v')
        (*grid)[i][y] = 'v';
    else
        return ;
    printf("=======================================\n");
    var_dump(*grid, map->n_row, map->n_colums);
    printf("======================================\n");
    dfs(grid, i, y + 1, map);
    dfs(grid, i, y - 1, map);
    dfs(grid, i + 1, y, map);
    dfs(grid, i - 1, y, map);
}

void ft_flood_fill(char ***grid, int i, int y, t_map *map)
{
    // printf("========\n");
    // var_dump(*grid, map->n_row, map->n_colums);
    // printf("========\n");
    dfs(grid, i, y + 1, map);
    dfs(grid, i, y - 1, map);
    dfs(grid, i + 1, y, map);
    dfs(grid, i - 1, y, map);
}

int ft_count_collectible(char **grid, int r, int c)
{
    int counter = 0;
    int i = 0;
    while (i < r) {
        int j = 0;
        while (j < c) {
            if (grid[i][j] == 'C')
                counter++;
            j++;
        }
        i++;
    }
    return counter;
}

int ft_check_map_status(char ***grid, int x, int y, t_map *map)
{
    int collectible = ft_count_collectible(*grid, map->n_row, map->n_colums);
    // printf("\n==========>number of collectibles : (%d) <============\n", collectible);
    if (collectible != 0)
        return 0;
    if ((*grid)[x][y + 1] == 'v' || (*grid)[x][y - 1] == 'v' || (*grid)[x + 1][y] == 'v' || (*grid)[x - 1][y] == 'v')
        return 1;
    return 0;
}

int ft_check_valid_path(t_map *map, int n_rows, int n_cols)
{
    int x_player = ft_getx_component_position(map->grid, n_rows, n_cols, 'P');
    int y_player = ft_gety_component_position(map->grid, n_rows, n_cols, 'P');
    int x_exit = ft_getx_component_position(map->grid, n_rows, n_cols, 'E');
    int y_exit = ft_gety_component_position(map->grid, n_rows, n_cols, 'E');
    char **map1 = ft_init_map(map->grid, n_rows, n_cols);
    map1[x_player][y_player] = 'v';
    // printf("========\n");
    // var_dump(map1, n_rows, n_cols);
    // printf("========\n");
    ft_flood_fill(&map1, x_player, y_player, map);
    if (!ft_check_map_status(&map1, x_exit, y_exit, map))
        return 0;
    return 1;
}
/*
    end of flood fill algorithm
*/

int ft_check_walls(char c)
{
    if (c == '1')
        return (1);
    return (0);
}

int ft_check_component(t_slong **game, char c)
{
    if (c == '1')
        return (1);
    else if (c == '0')
        return (1);
    else if (c == 'C')
    {
        (*game)->map->col = (*game)->map->col + 1;
        return (1);
    }
    else if (c == 'E')
    {
        (*game)->map->exit = (*game)->map->exit + 1;
        return (1);
    }
    else if (c == 'P')
    {
        (*game)->map->player = (*game)->map->player + 1;
        return (1);
    }
    return (0);
}

int ft_check_bounds(t_slong **game)
{
    if ((*game)->map->col < 1)
        return (0);
    if ((*game)->map->exit != 1)
        return (0);
    if ((*game)->map->player != 1)
        return (0);
    return (1);
}

int ft_check_map_component(t_slong **game, int rows, int cols)
{
    int i;
    int j;

    i = -1;
    while (++i < rows)
    {
        j = -1;
        while (++j < cols)
        {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
            {
                if (! ft_check_walls((*game)->map->grid[i][j]))
                    return(0);
            }
            else if (! ft_check_component(game, (*game)->map->grid[i][j]))
                return (0);
        }
    }
    if (! ft_check_bounds(game))
        return (0);
    return (1);
}

int ft_validate_map(t_slong *game)
{
    if (game->map->n_row == game->map->n_colums)
        return (0);
    if (! ft_check_map_component(&game, game->map->n_row, game->map->n_colums))
    {
        printf("\n==> map component error <==\n");
        return (0);
    }
    if (! ft_check_valid_path(game->map, game->map->n_row, game->map->n_colums))
        return (0);
    game->map->col = ft_count_collectible(game->map->grid, game->map->n_row, game->map->n_colums);
    printf("\n==> map component is Valid <==\n");
    return (1);
}

/*
    ===> end of validating the map
*/
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








/*
=============================================================>mlx (code ) and implimentaion<==============================================
*/




int ft_get_image_id_helper(char compenent)
{
    if (compenent == '1')
        return (11);
    return (12);
}

int ft_get_image_id(char component, int i, int j, t_map *map)
{
    if (i == 0 && j == 0)
        return (0);
    else if (i == 0 && j == map->n_colums - 1)
        return (1);
    else if ( i == 0)
        return (2);
    else if (i == map->n_row -1 && j == 0)
        return (3);
    else if (i == map->n_row -1 && j == map->n_colums - 1)
        return (4);
    else if ( i == map->n_row -1)
        return (5);
    else if (j == 0)
        return (6);
    else if (j == map->n_colums - 1)
        return (7);
    else if (component == 'P')
        return (8);
    else if (component == 'C')
        return (9);
    else if (component == 'E')
        return (10);
    return (ft_get_image_id_helper(component));
}

char *ft_get_absolute_component(int id)
{
    if (id == 0)
        return ("imgs/tl.xpm");
    else if (id == 1)
        return ("imgs/tr.xpm");
    else if (id == 2)
        return ("imgs/t.xpm");
    else if (id == 3)
        return ("imgs/bl.xpm");
    else if (id == 4)
        return ("imgs/br.xpm");
    else if (id == 5)
        return ("imgs/b.xpm");
    else if (id == 6)
        return ("imgs/l.xpm");
    else if (id == 7)
        return ("imgs/r.xpm");
    return ("imgs/0.xpm");
}


char *ft_get_image_name(t_slong game, int img_id)
{
    char *img_name;

    if ((img_id >= 0 && img_id <= 7) || img_id == 11)
        img_name = ft_get_absolute_component(img_id);
    else if (img_id == 8)
    {
        img_name =  game.player->img[0];
    }
    else if (img_id == 9)
    {
        img_name = "imgs/key.xpm";
    }
    else if (img_id == 10)
    {
        img_name = "imgs/exit.xpm";
    }
    return (img_name);
}

/*
    i need to specify the compenent that well have any animation 
*/

char *ft_strcpy(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i]!= '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

int ft_setup_image(t_slong game, int i, int j, int image_id)
{
    void    *img;
    char    *img_path;
    int     fd;

    game.player = malloc(sizeof(t_player));
    game.player->img[0] =  malloc(ft_strlen("img/p1.xpm") +1);
    game.player->img[1] =  malloc(ft_strlen("img/p2.xpm") +1);
    ft_strcpy( game.player->img[0],"imgs/p1.xpm");
    ft_strcpy( game.player->img[1],"imgs/p2.xpm");

    img_path = ft_get_image_name(game, image_id);
    printf("\n====>image name: (%s)<===\n", img_path);
    fd = open(img_path, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (0);
    }
    img = mlx_xpm_file_to_image(game.mlx, img_path, (int *)18, (int *)18);
    if (!img)
        return (0);
    mlx_put_image_to_window(game.mlx,game.win , img, i * 18, j *18);
    return (1);
}

int ft_gen_window(t_slong game)
{
    int     i;
    int     j;
    int     flag;

    i = 0;
    while (i < game.map->n_row)
    {
        j = 0;
        while (j < game.map->n_colums)
        {
            flag = ft_get_image_id(game.map->grid[i][j], i , j , game.map);   
            if (! ft_setup_image(game, i, j, flag))
            {
                printf("\n==>error here (%d)(%d)<==\n", i, j);
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

int ft_init_game(t_slong game)
{
    int with;
    int height;

    with = game.map->n_colums * 18;
    height = game.map->n_row * 18;
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, with, height, "So_oLong");
	if (! ft_gen_window(game))
    {
        printf("\n====>errrrrrrrrrrrrrrrrrrrrrrrrrrror<==\n");
        return (0);
    }
    mlx_loop(game.mlx);
    return (1);
}



/*
============================================================>end of mlx implimention<=====================================================
*/



int main(int ac, char **av)
{
    t_slong game;

    if (ac != 2)
        return 1;

    if (!ft_init_requirement(&game, av[1]))
        return (printf("==> MAP ERROR <==\n"), ft_destroy_game(&game), 1);
    if (! ft_validate_map(&game))
        return (printf("==> MAP ERROR IN VALIDATING <==\n"),ft_destroy_game(&game), 1);
    if (!ft_init_game(game))
        ft_destroy_game(&game);
    return 0;
}
    // var_dump(game.map->grid, game.map->n_row, game.map->n_colums);
    
    // // // Other operations if needed
