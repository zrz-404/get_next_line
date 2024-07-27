/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:52:40 by jroseiro          #+#    #+#             */
/*   Updated: 2024/07/27 13:28:36 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	static int	buf_i; // buffer index
	static int	b_read;	// bytes read
	char		*line;	// line itself
	char		*nline;	// extra line buf
	int			l_size; // line size + counter
	int			l_cap;	// line capacity
	int			i;
	char		c;

	i = 0;
	l_cap = 0;
	buf_i = 0;
	b_read = 0;
	l_size = 0;
	nline = NULL;
	l_cap = BUFFER_SIZE;
	if (fd < 0)
		return (NULL);
	line =(char *)malloc(l_cap); // allocating inital memory for the line
	if (!line) // if *line isnt alloc then NULL
		return (NULL);
	while (1)
	{	// read more data into buffer if needed
		if (buf_i >= b_read)
		{
			b_read = read(fd, buf, BUFFER_SIZE);
			buf_i = 0;
			if (b_read <= 0)
				break; // stop when EOF or error
		}
	}

	// now we process the buffer to extract the line we want to return
	while (buf_i < b_read)
	{
		c = buf[buf_i++];
		if (l_size >= l_cap - 1) // check if we need to expand line buf
		{	// allocate a new buffer with double capacity
			l_cap *= 2;
			nline = (char *)malloc(l_cap);
			if (!nline)
			{
				free(line);
				return (NULL);
			}
			while (i < l_size)
			{
				nline[i] = line[i];
				i++;
			}
			free(line);
			line = nline; // making the main line *the line* again
		}
		line[l_size++] = c; // assign each char to the returning line
		if (c == '\n')
		{
			line[l_size] = '\0'; //when \n found we cut off the line and return it
			return (line);
		}
	}
	if (l_size > 0) // in case we have a file without a newline '\n'
	{
		line[l_size] = '\0';
		return (line);
	}
	free(line);
	return (NULL);
}
