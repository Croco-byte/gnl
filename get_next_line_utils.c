/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:04:06 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 13:31:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			has_return(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	char	*result;

	i = 0;
	k = 0;
	if (!s1 && !s2)
		return (0);
	if (!(result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (0);
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	while (k < ft_strlen(s2))
	{
		result[i + k] = s2[k];
		k++;
	}
	result[i + k] = '\0';
	free((char *)s1);
	return (result);
}

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
