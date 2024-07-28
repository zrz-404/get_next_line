/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:52:46 by jroseiro          #+#    #+#             */
/*   Updated: 2024/07/27 13:28:33 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
// char	*ft_strdup(char *s1)
// {
// 	read(s1,);
// 	return (NULL);
// }
// size_t	ft_strlen(char *s)
// {
// }
// char	ft_substr(char *s, unsigned int start, size_t len);
// open()
// read()
// Plan:
//     1. Allocate array of char * that will store line
//     2. Call read() untill we gonna reach last char index that stored in t_line_data
//     3. Start filling array of char * with new line, if the first array is full, go to next one
//         and allocate memory for it.
//     4. After getting either \n or \0 quit loop and then count the total len of all arrays char *
//     5. allocate new array that will be result of size arrays char *
//     6. copy all data from arrays of char * to the result array.
//     7. free stuff
//     8. return array.
//     SOUNDS EASY
//     Also, we can manage the max BUFFER_SIZE by creating macro MAX_BUFFER_SIZE and then
//         we just gonna apply mod. It's needed because someone can use BUFFER_SIZE more than
//         we have memory at all.
//     NOTES:
//     1. read() function completely rewrite buf, so each call will erase content
//         that was writen before. That's a issue, because read() also will move
//         pointer to the next char. And we cannot just get size of line and
//         just only then write it to the buffer. We have to make 1 call, which
//         will write correct line to the buffer. We CANNOT allocate buffer
//         just for the specific line.
//     2. The line itself could be longer than BUFFER_SIZE, so how we can determine
//         the correct size of the result array?
//     3. Main idea of handling proper buff size is just create
//         array of c arrays and allocate new array if pervious is full.
//         The issue of this approach is that it also has max limit,
//         but for now I cannot find better approach than this one.
// -----
// 	static vars allow us to keep calling a function without
// 	loosing a value in a program.
// 	Each time get_next_line is called in the int main,
// 	it will still have the same information stored in its buffer
// 	until the target (so, fd in this case) of the program changes.
// 	We can just go through the buffer as if it was a normal string
// 	and copy its current index into a different variable which gets
// 	then returned to the terminal. We just search and copy each char
// 	present in the buffer until '\n' or '\0' and then simply return
// 	the string each time. This is the main loop which allows the
// 	program to go through the entire file descriptor.
// int main()
// {
// 	get_next_line(fd);
// 	return 0;
// }
