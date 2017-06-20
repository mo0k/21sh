/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/19 15:53:02 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	next_history(t_readline *r, t_history *h)
{
	//t_r	*r;
	//t_history	*h;

	if (!r || !h)
		return (1);
	//r = &sh->r;
	//h = &sh->h;
	//if (!h || !r)
	///	return (0);
	if (!(h->ret = move_history(r, h, down)))
	{
		if (r->pos > 0)
			tputs(tgoto(tgetstr("LE", NULL), 0, r->pos), AFFCNT, &my_putc);
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putc);
		if (r->temp == &r->line)
			ft_putchar(7);
		r->temp = &r->line;
		//print_line(*r->temp, r->in_newline);
		ft_putstr(*r->temp);
		r->pos = ft_strlen(*r->temp);
		padding_limit(r->pos, r->prompt.len, r->win.col);
	}
	return (1);
}
