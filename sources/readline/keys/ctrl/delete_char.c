/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/02 22:46:38 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int	delete_char(t_readline *e, t_history *history)
{
	// BROKEN
	//
	//
	//
	////////////
	char **line;
	int pos;
	int len_line;

	if (!e)
		return (0);
	line = e->temp;
	pos = e->pos;
	len_line = ft_strlen(*line);
	if (e->pos < len_line)
	{
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
			ft_putstr(*line + pos + 1);
		if (e->pos < --len_line )
			tputs(tgoto(tgetstr("LE", NULL), 1, len_line - pos), AFFCNT, &my_putchar);
		//return (1);
	}
	//tputs(tgetstr("dc", NULL), AFFCNT, &my_putchar);
	ft_delchar(line, pos);
	if (history && history->ret && history->history_cur)
		((t_history_elem*)(history->history_cur->content))->flag_modif = 1;
	return (1);
}
