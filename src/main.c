/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho <aghergho@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:49:16 by aghergho          #+#    #+#             */
/*   Updated: 2024/04/01 13:29:09 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int ft_check_extension(char *str)
{
    char    *extention;

    extention = ft_strchr(str, '.');
    if (!extention)
        return (0);
    if (ft_strcmp(extention, ".ber"))
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    // t_slong     *map;

    if (ac > 2 || ac == 1)
        return (0);
    if (!ft_check_extension(av[1]))
        return (printf("\nERROR\n"));
    return (0);
}