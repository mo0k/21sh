/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:08:57 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/06 10:36:32 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITLINE_H
# define EDITLINE_H


typedef struct	s_editline
{
	char		*line;
	char		**temp;
	int 		pos;
}				t_editline;

# include <ft_21sh.h>

void	init_line(t_editline *editline);
void	reset_line(char **line, int *pos);

#endif