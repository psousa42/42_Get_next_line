/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:58:07 by psousa          #+#    #+#             */
/*   Updated: 2022/11/22 11:58:07 by psousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_rs(int fd, char *save);
char	*ft_gl(char *save);
char	*ft_s(char *save);

size_t	ft_strlen( char *str);
char	*ft_strjoin(char *str, char *src);
char	*ft_strchr(char *str, int n);

#endif
