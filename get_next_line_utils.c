/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <lucas.lebugle@student.s19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:53:14 by llebugle          #+#    #+#             */
/*   Updated: 2024/11/03 17:41:56 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*(s + size))
		size++;
	return (size);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*new;
	unsigned char	*p;
	size_t			i;

	if (size != 0 && (nmemb > SIZE_MAX / size))
		return (NULL);
	new = malloc(nmemb * size);
	if (!new)
		return (NULL);
	i = 0;
	p = (unsigned char *)new;
	while (i++ < nmemb * size)
		*p++ = 0;
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	str[len] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i] && i < len)
		new[i] = s1[i];
	j = -1;
	while (s2[++j] && i + j < len)
		new[i + j] = s2[j];
	new[i + j] = '\0';
	if (s1)
		free(s1);
	return (new);
}
