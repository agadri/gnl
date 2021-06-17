/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:49:59 by adegadri          #+#    #+#             */
/*   Updated: 2021/06/17 15:50:08 by sbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_end(char *str);
char	*ft_resave(char *save);
int		get_next_line(int fd, char **line);

#endif
