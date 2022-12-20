/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:25:32 by agallet           #+#    #+#             */
/*   Updated: 2022/12/20 09:16:28 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join(char *s1, char *s2)
{
	char	*_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	_str = NULL;
	_str = malloc(sizeof(char)
			* (ft_strlen(s1, '\0') + ft_strlen(s2, '\n') + 1));
	if (_str)
	{
		while (s1 && s1[i] && s1[i] != '\n')
		{
			_str[i] = s1[i];
			i++;
		}
		while (s2 && s2[j] && s2[j] != '\n')
			_str[i++] = s2[j++];
		if (s2 && s2[j] && s2[j] == '\n')
			_str[i++] = s2[j];
		_str[i] = '\0';
	}
	ft_clear(&s1);
	return (_str);
}

char	*new_buffer(char **buffer, char *line)
{
	char	*_str;

	_str = NULL;
	if (!*buffer)
		return (NULL);
	if (right_side(*buffer) && line)
		_str = ft_strdup(*buffer);
	ft_clear(&(*buffer));
	if (!_str)
		return (NULL);
	return (_str);
}

int	verif_line(char *buffer, char **line)
{
	if (buffer)
	{
		*line = ft_join(*line, buffer);
		if (!line)
			return (0);
		if (ft_strchr(buffer, '\n') >= 0)
			return (0);
	}
	return (1);
}

void	ft_line(int *verif, char **buffer, char **line, int *fd)
{	
	if (!*buffer)
	{
		ft_clear(&(*buffer));
		ft_clear(&(*line));
		*verif = -1;
	}
	if (*verif && *verif != -1)
	{
		*verif = read(*fd, *buffer, BUFFER_SIZE);
		(*buffer)[*verif] = '\0';
	}
}

char	*get_next_line(int fd)
{
	static char	*_buffer[10240];
	char		*_line;
	int			_verif;
	int			start;

	_line = NULL;
	_verif = 1;
	start = 0;
	if (fd < 0 || fd >= 10240 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_clear(&_buffer[fd]));
	*_buffer = _buffer[fd];
	while (_verif && _verif != -1)
	{
		_verif = verif_line(*_buffer, &_line);
		if (_verif && *_buffer && !start)
			ft_clear(&(*_buffer));
		if (!*_buffer && _verif && !start)
			*_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		ft_line(&_verif, &(*_buffer), &_line, &fd);
		start = 1;
	}
	_buffer[fd] = new_buffer(&(*_buffer), _line);
	return (_line);
}
