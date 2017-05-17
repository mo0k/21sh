/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:08:57 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/16 16:00:38 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITLINE_H
# define EDITLINE_H

enum e_cut
{
	key_u = 1,
	key_k,
	key_w
};

typedef struct	s_editline
{
	char		*line;
	char		**temp;
	char		*strcpy;
	int 		pos;
	enum e_cut		cut;
}				t_editline;

# include <ft_21sh.h>

void	init_line(t_editline *editline);
void	reset_line(char **line, int *pos);

#endif