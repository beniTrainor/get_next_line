/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrainor <btrainor@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:10:22 by btrainor          #+#    #+#             */
/*   Updated: 2026/11/05 19:05:38 by btrainor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_free(char **buf)
{
	if (*buf)
		free(*buf);
	*buf = NULL;
	return (NULL);
}

char	*read_and_stash(int fd, char *stash)
{
	ssize_t	bytes;
	char	*buf;

	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (ft_free(&stash));
		}
		buf[bytes] = '\0';
		stash = ft_strjoin_free(stash, buf);
		if (!stash)
			break ;
	}
	free(buf);
	if (stash && !*stash)
		return (ft_free(&stash));
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;

	if (!stash)
		return (NULL);
	line = ft_substr(stash, 0, ft_strchr(stash, '\n') - stash + 1);
	if (!line)
		return (NULL);
	return (line);
}

char	*update_stash(char *stash)
{
	char	*tmp;

	if (!stash)
		return (NULL);
	tmp = stash;
	stash = ft_substr(stash, ft_strchr(stash, '\n') - stash + 1,
			ft_strchr(stash, '\0') - ft_strchr(stash, '\n'));
	if (!stash)
		return (NULL);
	free(tmp);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}

//int	main(void)
//{
//	int		fd;
//	char	*line;
//
//	fd = open("./gnlTester/files/41_no_nl", O_RDONLY);
//	//fd = open("./easy.txt", O_RDONLY);
//	line = "";	
//	while (line != NULL)
//	{
//		line = get_next_line(fd);
//		printf("%s", line);
//		free(line);
//	}
//	close(fd);
//}
