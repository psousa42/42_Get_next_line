/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:28:26 by psousa          #+#    #+#             */
/*   Updated: 2022/11/21 14:28:27 by psousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_s(char *save)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	dest = malloc(((ft_strlen(save) - i) + 1) * sizeof(char));
	i++;
	j = 0;
	while (save[i])
		dest[j++] = save[i++];
	dest[j] = '\0';
	free(save);
	return (dest);
}

char	*ft_gl(char *save)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	while (j <= i)
	{
		line[j] = save[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_rs(int fd, char *save)
{
	char	*buf;
	int		read_byte;

	if (ft_strchr(save, '\n'))
		return (save);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	read_byte = 1;
	while (!ft_strchr(save, '\n') && read_byte > 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_byte] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_rs(fd, save);
	if (!save)
		return (NULL);
	line = ft_gl(save);
	save = ft_s(save);
	return (line);
}

/*int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("files/miranha.txt", O_RDONLY);
	//fd = open("files/simpsons.txt", O_RDONLY); 
	//fd = open("files/hp.txt", O_RDONLY);
 	//fd = open("files/hltv.txt", O_RDONLY);
	//fd = open("files/big_line_with_nl", O_RDONLY);
	//fd = open("files/big_line_no_nl", O_RDONLY); 
	i = 1;
	while ((line = get_next_line(fd)))
	{
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}*/
