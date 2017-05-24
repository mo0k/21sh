/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:32:34 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 01:50:11 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	line_up(char *line, int *pos)
{
	if (!line)
		return (0);
	int len_prompt = stock_data(NULL)->prompt.len;
	int cols = stock_data(NULL)->win.col;
	(void)line;

	if (len_prompt + *pos > cols - 1)
	{
		if (*pos - (cols - len_prompt - 1) > len_prompt)
		{
			//printf("par la\n");
			tputs(tgetstr("up", NULL), AFFCNT, &my_putchar);
			*pos -= cols;
		}
		else
		{
			//printf("par ici\n");
			if ((*pos + stock_data(NULL)->prompt.len) % stock_data(NULL)->win.col == 0)
			{
				tputs(tgetstr("up", NULL), AFFCNT, &my_putchar);
				tputs(tgoto(tgetstr("RI", NULL), 1, len_prompt), AFFCNT, &my_putchar);
			}
			else
			{
				tputs(tgoto(tgetstr("LE", NULL), 1, *pos - (cols - len_prompt)), AFFCNT, &my_putchar);
				tputs(tgetstr("up", NULL), AFFCNT, &my_putchar);
				tputs(tgoto(tgetstr("RI", NULL), 1, len_prompt), AFFCNT, &my_putchar);
			}
			*pos = 0;
		}
	}
	return (1);
}
