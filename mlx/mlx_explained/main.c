
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

void	ft_check_rules(map_data *map)
{
	if (map->grid[i][j] == 'c')
		map->col_obj++;
	if (map->grid[i][j] == 'p')
		map->player_obj++;
	if (map->grid[i][j] == 'E')
		map->exit_obj++;
}

int ft_itirate_map(map_data *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->num_rows)
	{
		j = 0;
		while (j < map->num_col)
		{
			if (map->grid[0][j] != '1' || map->grid[map->num_rows - 1][j] != '1') 
				return (0);
			if (map->grid[i][0] != '1' || map->grid[i][map->num_col - 1] != '1')
				return (0);
			ft_check_rules(map);
			j++;
		}
		if (map->exit_obj > 1 || map->player_obj > 1)
			return (0);
		i++;
	}
	if (map->col_obj < 1)
		return(0);
	return (1);	
}

void	ft_clean_grid(char **grid, int index)
{
	int		i;

	i = 0;
	while (i <= index)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL;
}

char	*ft_edit_line(char *line)
{
	char *n_line;
	int		i;

	i = 0;
	n_line = malloc(sizeof(char) * ft_strlen(line) + 1);
	while (line[i] && line[i] != '\n')
	{
		n_line[i] = line[i];
		i++;
	}
	n_line[i] = '\0';
	free(line);
	return (n_line);
}

int ft_count_lines(int fd)
{
	int		n_line;
	char	*line;

	n_line = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		n_line++;
		free(line);
		line = get_next_line(fd);
	}
	return (n_line);
}

int	ft_gen_map(map_data *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->grid[i] = ft_edit_line(line);
		if (!map->grid[i])
		{
			ft_clean_grid(map->grid, i);
			free(line);
			return(0);
		}
		if (i == 0)
			map->num_col = ft_strlen(map->grid[i]);
		if (ft_strlen(map->grid[i]) != map->num_col)
			return (0);
		free(line);
		++i;
		line = get_next_line(fd);
	}
	return (1);
}

int	ft_validate_map(argv[1])
{
	map_data  map;
	int n_row;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	n_row = ft_count_lines(fd);
	if (n_row < 3)
		return (0);
	map->grid = malloc(sizeof(char *) * n_row);
	if (!map->grid)
		return (0);
	map->num_rows = n_row;
	if (!ft_gen_map(&map, fd))
		return (0);
	if (!ft_itirate_map(map))
		return (0);
	return (1);
}

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        perror("PLEAS TRY AGIAN! try to enter just one valid Map");
        return (0);
    }
	if (!ft_validate_map(argv[1]))
	{
        perror("PLEAS TRY AGIAN! with one map with mbp type");
		return (0);
	}
	return (1);
}