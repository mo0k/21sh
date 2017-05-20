/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/20 13:34:34 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	next_history(t_editline *editline, t_history *h)
{
	if (!h || editline)
		return (0);
	if (!(h->ret = move_history(&h->history_cur, &h->in, down, editline)))
	{
		if (editline->pos > 0)
			tputs(tgoto(tgetstr("LE", NULL), 0, editline->pos),AFFCNT, &my_putchar);
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		if (editline->temp == &editline->line)
			ft_putchar(7);
		editline->temp = &editline->line;
		ft_putstr(*editline->temp);
		editline->pos = ft_strlen(*editline->temp);
	}
	return (1);
}
