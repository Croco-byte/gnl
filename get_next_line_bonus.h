/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:04:33 by user42            #+#    #+#             */
/*   Updated: 2020/11/26 13:41:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		has_return(char *str);
size_t	ft_strlen(const char *str);
char	*line_from_save(char *save);
char	*update_save(char *save, int *last_line);
char	*ft_strjoin(char const *s1, char const *s2);
int		malloc_fails(char **line, char *save, int *last_line);
int		is_last_line(char *save, int *last_line, int i);

#endif
