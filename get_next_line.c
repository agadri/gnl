/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:56:28 by adegadri          #+#    #+#             */
/*   Updated: 2021/06/15 19:04:17 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save(char *save)
{
	int	i;
	char	*dst;
	
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
	{
		save = NULL;
		free(save);
		return (NULL);
	}
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		dst[i] = save[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_resave(char *save)
{
	int	i;
	int	len;
	char	*dst;
	int	j;
	
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	i++;
	len = ft_strlen(save);
	dst = (char *)malloc(sizeof(char) * ((len - i) + 1));
	if (!dst)
	{
		save = NULL;
		free(save);
		return (NULL);
	}
	j = 0;
	while (save[i])
		dst[j++] = save[i++];
	save = NULL;
	free(save);
	dst[j] = '\0';
	return (dst);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*save;
	int			rd;

	rd = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (-1);
	while (!ft_strchr(save, '\n') && rd != 0)
	{
		rd = read(fd,buffer,BUFFER_SIZE);
		buffer[rd] = '\0';
		if (rd == -1 )
			return(-1);
		if (rd == 0)
			break ; 
		save = ft_strjoin(save, buffer);
	}
	if (ft_end(save) == 1)
		*line = ft_save(save);
	if (rd == 0)
		return (0);
	save = ft_resave(save);
	return (1);
}
/*
int	 main()
{
	char *line;
	int		ret;
	ret = open("fichier2.txt", O_RDONLY);
	printf ("ret :%d\n", get_next_line(ret, &line));
	printf("line :%s\n", line);
	printf ("ret :%d\n", get_next_line(ret, &line));
	printf("line :%s\n", line);
	printf ("ret :%d\n", get_next_line(ret, &line));
	printf("line :%s\n", line);
	printf ("ret : %d\n", get_next_line(ret, &line));
	printf("line :%s\n", line);
	printf ("ret : %d\n", get_next_line(ret, &line));
	printf("line :%s\n", line);
	printf ("ret : %d\n", get_next_line(ret, &line));
	printf("line :%s\n", line);
	printf ("ret : %d\n", get_next_line(ret, &line));
	printf("line :%s\n", line);
	printf ("ret : %d\n", get_next_line(ret, &line));
	return (0);
}
*/
