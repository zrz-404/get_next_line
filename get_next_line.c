
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
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	buf_i;
	static int	b_read;
	char		*line;
	char		*nline;
	int			l_size;
	int			l_cap;
	int			i;
	char		c;

	l_cap = 0;
	nline = NULL;
	l_size = 0;
	l_cap = BUFFER_SIZE + 1;
	if (fd < 0)
		return (NULL);
	line =(char *)malloc(l_cap);
	if (!line)
		return (NULL);
	while (1)
	{
		if (buf_i >= b_read)
		{
			b_read = read(fd, buf, BUFFER_SIZE);
			buf_i = 0;
			if (b_read <= 0)
				break;
		}
		while (buf_i < b_read)
		{
			c = buf[buf_i++];
			if (l_size >= l_cap - 1)
			{
				l_cap *= 2;
				nline = (char *)malloc(l_cap);
				if (!nline)
				{
					free(line);
					return (NULL);
				}
				i = 0;
				while (i < l_size)
				{
					nline[i] = line[i];
					i++;
				}
				free(line);
				line = nline;
			}
			line[l_size++] = c;
			if (c == '\n')
			{
				line[l_size] = '\0';
				return (line);
			}
		}
	}
	if (l_size > 0)
	{
		line[l_size] = '\0';
		return (line);
	}
	free(line);
	return (NULL);
}

// int main(void)
// {
// 	printf("######  FILE ANALYSIS STARTS HERE  ######\n\n\n\n\n");
//     int fd = open("text.txt", O_RDONLY);
//     if (fd >= 0)
//     {
//         char *line;
//         while ((line = get_next_line(fd)) != NULL)
//         {
//             printf("Line: %s", line);
//             free(line);
//         }
//         close(fd);
//     }
//     return 0;
// }
