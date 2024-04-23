/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:32:08 by valarcon          #+#    #+#             */
/*   Updated: 2022/02/28 10:32:10 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_freenull(const char *str, char *s, int mode)
{
	char	*str2;
	int		c;

	if (mode == 1)
	{
		free (s);
		s = NULL;
		return (0);
	}
	if (mode == 2)
	{
		str2 = (char *)str;
		c = 0;
		while (*str2)
		{
			c++;
			str2++;
		}
		return (c);
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		k;
	char	*s2;
	char	*s1a;
	int		p;

	s1a = (char *)s1;
	k = 0;
	while (*(s1a + k))
		k++;
	s2 = malloc(sizeof(char) * (k + 1));
	if (s2 == '\0')
		return (0);
	p = k;
	while (k + 1 > 0)
	{
		*(s2 + k) = *(s1a + k);
		k--;
	}
	*(s2 + p) = '\0';
	return (s2);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		a;
	int		b;
	char	*ss;

	if (!s1 || !s2)
		return (NULL);
	a = ft_freenull(s1, 0, 2);
	b = a + ft_freenull(s2, 0, 2);
	ss = malloc(sizeof(char) * (b + 1));
	if (ss == 0)
		return (0);
	*(ss + b) = 0;
	while (b - a >= 0 && s2)
	{
		*(ss + b) = *(s2 + b - a);
		b--;
	}
	while (a > 0)
	{
		*(ss + a - 1) = *(s1 + a - 1);
		a--;
	}
	return (ss);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	c;
	char	*src2;
	size_t	n;

	n = 0;
	c = 0;
	src2 = (char *)src;
	while (*(src2 + c) && c + 1 < size)
	{
		dest[c] = src2[c];
		c++;
	}
	c = 0;
	while (*(src2 + c) && *(dest + c) && c + 1 < size)
	{
		dest[c] = src2[c];
		c++;
	}
	if (size > 0)
		dest[c] = '\0';
	while (*(src2 + n))
		n++;
	return (n);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	k;
	char			*s2;

	k = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_freenull(s, 0, 2))
	{
		s2 = malloc(sizeof(char));
		s2[0] = 0;
		return (s2);
	}
	if (ft_freenull(s, 0, 2) < (int)len)
		len = (size_t)ft_freenull(s, 0, 2);
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == '\0')
		return (0);
	while (len > k && (*(s + start + k)))
	{
		*(s2 + k) = *((unsigned char *)s + start + k);
		k++;
	}
	*(s2 + k) = '\0';
	return (s2);
}
