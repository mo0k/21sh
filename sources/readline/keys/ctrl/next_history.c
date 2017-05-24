/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 01:12:30 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	next_history(t_shell *sh)
{
	t_editline	*r;
	t_history	*h;

	if (!sh)
		return (0);
	r = &sh->editline;
	h = &sh->history;
	if (!h || !r)
		return (0);
	if (!(h->ret = move_history(sh, down)))
	{
		if (r->pos > 0)
			tputs(tgoto(tgetstr("LE", NULL), 0, r->pos), AFFCNT, &my_putchar);
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		if (r->temp == &r->line)
			ft_putchar(7);
		r->temp = &r->line;
		ft_putstr(*r->temp);
		r->pos = ft_strlen(*r->temp);
		padding_limit(r->pos, sh->prompt.len, sh->win.col);
	}
	return (1);
}
