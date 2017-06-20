/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_line_discard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 03:30:58 by jmoucade          #+#    #+#             */
/*   Updated: 2017/06/19 15:53:41 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

static	void do_front(t_readline *r)
{
	if (r->pos)
		tputs(tgoto(tgetstr("LE", NULL), 1, r->pos), AFFCNT, &my_putc);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putc);
	//print_line(*r->temp, r->in_newline);
	ft_putstr(*r->temp);
	r->pos = ft_strlen(*r->temp);
	if (r->pos)
		tputs(tgoto(tgetstr("LE", NULL), 1, r->pos), AFFCNT, &my_putc);
	r->pos = 0;
}

static	int do_back(t_readline *r)
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

int 	unix_line_discard(t_readline *readline, t_history *history)
{
	if (!readline)
		return (1);
	if (!do_back(readline))
		return (1);
	do_front(readline);
	if (history && history->ret && history->history_cur)
		((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
	readline->cut = key_u;
	return (1);
}
