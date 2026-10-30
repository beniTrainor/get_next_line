/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrainor <btrainor@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:10:22 by btrainor          #+#    #+#             */
/*   Updated: 2026/10/30 15:45:43 by btrainor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	char		*buf;
	ssize_t		bytes;
	ssize_t		index;
	static char	*stash = NULL;
	char		*tmp;

	if (stash == NULL)
		stash = ft_strdup("");
	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	bytes = read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	if (bytes < 1)
	{
		free(buf);
		return (NULL);
	}
	while (bytes > 1)
	{
		tmp = stash;
		stash = ft_strjoin(stash, buf);
		free(tmp);
		index = ft_strindex(stash, '\n');
		if (index >= 0)
		{
			buf = ft_substr(stash, 0, index + 1);
			stash = ft_strdup(ft_strchr(stash, '\n') + 1);
			return (buf);
		}
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
	}
	return (buf);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./gnlTester/files/41_with_nl", O_RDONLY);
	//fd = open("./easy.txt", O_RDONLY);
	line = get_next_line(fd);	
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
