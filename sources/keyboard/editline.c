/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:44:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/14 16:12:20 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <editline.h>

void	init_line(t_editline *editline)
{
	editline->line = 0;
	editline->temp = 0;
	editline->strcpy = 0;
	editline->pos = 0;
}

void	reset_line(char **line, int *pos)
{
	if (!line || !pos)
		return;
	free(*line);
	*line = NULL;
	*pos = 0;
}

int 	is_eol(int len_prompt, int len_line, int cols, int pos_cur_in_line)
{
	int line_reste = len_line - (cols - len_prompt);
	int nbr_line = 1;
	//if (line_reste > 0) => PLusieur lines
	if (line_reste > cols)
		nbr_line += (line_reste / cols) + 1;
	else
		nbr_line += line_reste / cols;
	if (nbr_line == 1 && pos_cur_in_line + len_prompt == cols)
		return (1);
	return (0);
	//else if (line_reste > cols && )


}
