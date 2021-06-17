/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:49:59 by adegadri          #+#    #+#             */
/*   Updated: 2021/06/15 19:03:28 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

//#	define BUFFER_SIZE 10
int		ft_strlen(char *str);
char		*ft_strchr(char *str, int c);
char	*ft_strdup(char *s);
char		*ft_strjoin(char  *s1, char  *s2);
int		ft_end(char *str);
char		*ft_resave(char *save);
//static char 	*ft_save(char *save);
int		get_next_line(int fd, char **line);

#endif
