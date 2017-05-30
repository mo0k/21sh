/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:32:34 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 23:04:10 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	line_up(t_readline *readline)
{
	char 	*line;
	int		*pos;
	int 	col;
	int 	len_prompt;

	if (!readline)
		return 0;
	line = *readline->temp;
	pos = &readline->pos;
	if (!line)
		return (0);
	len_prompt = readline->prompt.len;
	col = readline->win.col;
	(void)line;

	if (len_prompt + *pos > col - 1)
	{
		if (*pos - (col - len_prompt - 1) > len_prompt)
		{
			tputs(tgetstr("up", NULL), AFFCNT, &my_putchar);
			*pos -= col;
		}
		else
		{
			if ((*pos + len_prompt) % col == 0)
			{
				tputs(tgetstr("up", NULL), AFFCNT, &my_putchar);
				tputs(tgoto(tgetstr("RI", NULL), 1, len_prompt), AFFCNT, &my_putchar);
			}
			else
			{
				tputs(tgoto(tgetstr("LE", NULL), 1, *pos - (col - len_prompt)), AFFCNT, &my_putchar);
				tputs(tgetstr("up", NULL), AFFCNT, &my_putchar);
				tputs(tgoto(tgetstr("RI", NULL), 1, len_prompt), AFFCNT, &my_putchar);
			}
			*pos = 0;
		}
	}
	return (1);
}
