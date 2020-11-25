/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:06:56 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 17:37:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*line_from_save(char *save)
{
	char	*line;
	int		i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!(line = malloc((i + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char		*update_save(char *save)
{
	int		i;
	int		k;
	char	*new_save;

	i = 0;
	k = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	else
		i++;
	if (!(new_save = malloc(((ft_strlen(save) - i) + 1) * sizeof(char))))
		return (0);
	while (save[i])
		new_save[k++] = save[i++];
	new_save[k] = '\0';
	free(save);
	return (new_save);
}

int		get_next_line(int fd, char **line)
{
	static char		*save = 0;
	char			buff[BUFFER_SIZE + 1];
	int				reader;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	reader = 1;
	while (has_return(save) != 1 && reader != 0)
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
			return (-1);
		buff[reader] = '\0';
		save = fast_join(save, buff);
	}
	*line = line_from_save(save);
	save = update_save(save);
	if (reader == 0)
		return (0);
	return (1);
}
