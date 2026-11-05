/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrainor <btrainor@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:10:52 by btrainor          #+#    #+#             */
/*   Updated: 2026/11/05 18:59:52 by btrainor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
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

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 1;
	while (s[i - 1] != '\0')
	{
		dup[i - 1] = s[i - 1];
		i++;
	}
	dup[i - 1] = '\0';
	return (dup);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (ft_free(&s1));
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (unsigned char)c && *s != '\0')
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
