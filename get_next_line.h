/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:52:59 by jroseiro          #+#    #+#             */
/*   Updated: 2024/07/27 13:28:38 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# include <stdlib.h>	// malloc, free
# include <fcntl.h> 	// open
# include <stdio.h>		//
# include <unistd.h>	// read

char	*get_next_line(int fd);
int		read_from_fd(int fd, char *buf, int *buf_i, int *b_read);
char	*expand_line_buffer(char *line, int *l_cap);
char	*extract_line(char *buf, int *buf_i, int *b_read, int *l_size, int *l_cap);

# endif
