/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:44:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 00:24:17 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

void	init_line(t_editline *editline)
{
	editline->line = 0;
	editline->temp = 0;
	editline->strcpy = 0;
	editline->pos = 0;
	editline->cut = 0;
}

void	reset_line(char **line, int *pos)
{
	if (!line || !pos)
		return;
	free(*line);
	*line = NULL;
	*pos = 0;
}

void	padding_limit(int pos, int len_prompt, int col)
{
	 if ((pos + len_prompt) % col == 0)
	{
		my_putchar(' ');
		tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
	}
}
