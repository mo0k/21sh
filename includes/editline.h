/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:08:57 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/14 16:30:24 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITLINE_H
# define EDITLINE_H


typedef struct	s_editline
{
	char		*line;
	char		**temp;
	char		*strcpy;
	int 		pos;
}				t_editline;

# include <ft_21sh.h>

void	init_line(t_editline *editline);
void	reset_line(char **line, int *pos);
int 	is_eol(int len_prompt, int len_line, int cols, int pos_cur_in_line);

#endif