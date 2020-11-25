/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:04:06 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 17:41:22 by user42           ###   ########.fr       */
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

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str_dest;
	unsigned char	*str_src;

	i = n;
	str_dest = (unsigned char *)dest;
	str_src = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (str_src < str_dest && str_dest <= str_src + n)
	{
		while (i--)
			str_dest[i] = str_src[i];
		return (dest);
	}
	while (i--)
		*str_dest++ = *str_src++;
	return (dest);
}

char		*fast_join(char const *s1, char const *s2)
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
	ft_memmove(result, s1, ft_strlen(s1));
	ft_memmove(result + ft_strlen(s1), s2, ft_strlen(s2));
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free((char *)s1);
	return (result);
}
