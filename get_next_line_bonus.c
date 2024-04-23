/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:25:01 by valarcon          #+#    #+#             */
/*   Updated: 2022/02/28 10:25:03 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	int		a;
	char	*b;

	a = 0;
	while (*(s + a) && *(s + a) != (char)c)
		a++;
	b = (char *)s + a;
	if ((char)c == *(s + a))
		return (b);
	else
		return (0);
}

static char	*ft_splitmovi(char **hold)
{
	int		i;
	char	*aux_hold;
	char	*hold_cpy;

	i = 0;
	while ((*hold)[i] != '\0')
	{
		if ((*hold)[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (i == 0 || !*hold)
		return (NULL);
	aux_hold = *hold;
	hold_cpy = ft_substr(aux_hold, 0, i);
	*hold = ft_strdup(&(*hold)[i]);
	ft_freenull(0, aux_hold, 1);
	return (hold_cpy);
}

static ssize_t	ft_r_l(char **hold, char **buff, char **lastline, int fd)
{
	int		restread;
	char	*aux_res;

	restread = 1;
	while (!ft_strchr(*hold, '\n') && restread)
	{
		restread = read(fd, *buff, BUFFER_SIZE);
		(*buff)[restread] = '\0';
		aux_res = *hold;
		*hold = ft_strjoin(aux_res, *buff);
		free (aux_res);
	}
	*lastline = ft_splitmovi(hold);
	if (restread == 0 && !(*hold)[0])
	{
		free (*hold);
		*hold = NULL;
		return (0);
	}
	if (!*lastline)
		ft_freenull(0, *lastline, 1);
	return (restread);
}

char	*get_next_line(int fd)
{
	static char	*hold[1024];
	char		*buff;
	char		*lastline;
	int			i[4];

	i[0] = 0;
	if (fd < 0 || fd > 1024)
		return (0);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	if (read(fd, buff, 0) < 0)
	{
		ft_freenull(0, buff, 1);
		return (NULL);
	}
	if (!hold[fd])
		hold[fd] = ft_strdup("");
	i[1] = ft_r_l(&hold[fd], &buff, &lastline, fd);
	free (buff);
	buff = NULL;
	if (i[1] <= 0 && !lastline)
		return (NULL);
	return (lastline);
}
