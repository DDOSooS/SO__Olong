/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:57:34 by aghergho          #+#    #+#             */
/*   Updated: 2023/12/15 11:57:40 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		check_end_line(char *str);
char	*str_sub(char *str, int len);

#endif
