/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:06:56 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 11:51:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		save = ft_strjoin(save, buff);
	}
	*line = line_from_save(save);
	save = update_save(save);
	if (reader == 0)
		return (0);
	return (1);
}
