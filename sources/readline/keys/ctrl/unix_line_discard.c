/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_line_discard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 03:30:58 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/25 01:14:08 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

static	void do_front(t_editline *r)
{
	if (r->pos)
		tputs(tgoto(tgetstr("LE", NULL), 1, r->pos), AFFCNT, &my_putchar);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(*r->temp);
	r->pos = ft_strlen(*r->temp);
	if (r->pos)
		tputs(tgoto(tgetstr("LE", NULL), 1, r->pos), AFFCNT, &my_putchar);
	r->pos = 0;
}

static	int do_back(t_editline *r)
{
	char *temp;

	if (r->strcpy)
		free(r->strcpy);
	if (!(r->strcpy = ft_strsub(*r->temp, 0, r->pos)))
		return (0);
	if (!(temp = ft_strdup(*r->temp + r->pos)))
		return (0);
	free(*r->temp);
	if (!(*r->temp = ft_strdup(temp)))
	{
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

int 	unix_line_discard(t_editline *editline, t_history *history)
{
	if (!editline || !history)
		return (0);
	if (!do_back(editline))
		return (0);
	do_front(editline);
	if (history->ret && history->history_cur)
		((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
	editline->cut = key_u;
	return (1);
}
