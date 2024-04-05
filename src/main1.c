#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>


int main()
{
    void    *mlx;
    void    *win;
    void    *img;
    // char    *xpm;
    int     fd;
    int     width = 48;
    int     height = 48;

    mlx = mlx_init();
    if (!mlx) {
        fprintf(stderr, "Failed to initialize mlx\n");
        return 1;
    }
    // xpm = "./../imgs/exit.xpm";
    win = mlx_new_window(mlx, 600, 600, "Hello world!");
    if (!win)
    {
        fprintf(stderr, "Failed to create window\n");
        return 1;
    }
    img = mlx_xpm_file_to_image(mlx, "./imgs/exit.xpm", &width, &height);
    if (!img)
    {
        printf("\n==> pointer value (%p)<==\n", img);
        fd =  open("./ imgs/exit.xpm", O_RDONLY);
        printf("\n===>  (%d)<===\n", fd);
        fprintf(stderr, "Failed to load image\n");
        return 1;
    }
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
    return 0;
}
