/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrainor <btrainor@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:10:52 by btrainor          #+#    #+#             */
/*   Updated: 2026/11/04 18:31:45 by btrainor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	slen;
	size_t	sslen;

	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	sslen = slen - start;
	if (sslen > len)
		sslen = len;
	sub = malloc(sizeof(char) * (sslen + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < sslen)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 1;
	while (src[i - 1] != '\0')
	{
		dst[i - 1] = src[i - 1];
		i++;
	}
	dst[i - 1] = '\0';
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, s);
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;	
	size_t	i;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c && *s != '\0')
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
