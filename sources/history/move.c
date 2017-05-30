/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:28:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 23:04:36 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>

static int	do_move(t_list *h, t_readline *r)
{
	if (r->pos > 0)
		tputs(tgoto(tgetstr("LE", NULL), 0, r->pos), AFFCNT, &my_putchar);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(((t_history_elem*)((h)->content))->value);
	r->temp = &((t_history_elem*)((h)->content))->value;
	(r->pos) = ft_strlen(*r->temp);
	padding_limit(r->pos, r->prompt.len, r->win.col);
	return (1);
}

static int 	move_up(t_list **h, t_readline *readline)
{
	if (!h ||!*h || !readline)
		return (0); 
	if ((*h)->prev)
	{
		*h = (*h)->prev;
		return (do_move(*h, readline));
	}
	else
	{
		ft_putchar(7);
		return(1);
	}
}

static int 	move_down(t_list **h, t_readline *readline)
{
	if (!h || !*h || !readline)
		return (0);
	if (*h && (*h)->next)
	{
		*h = (*h)->next;
		return (do_move(*h, readline));

	}
	else
		return (0);
}

static		int check_var(t_list **alst, t_readline *readline, int *flag_in)
{
	if (!alst || !*alst || !readline || !flag_in)
	{
		if (!*alst)
			ft_putchar(7);
		return (0);
	}
	if (!*flag_in)
	{
		while (*alst && (*alst)->next)
			*alst = (*alst)->next;
		*flag_in = 1;
	}
	return (1);
}
int 		move_history(t_readline *readline, t_history *h, enum e_move move)
{
	t_list		**cur;
	int			*history_in;
	//t_readline	*readline;

	if (!h || !readline)
		return (0);
	cur = &h->history_cur;
	history_in = &h->in;
	//readline = &sh->readline;
	if (!check_var(cur, readline, history_in))
		return (0);
	if (*history_in == 1 && move == up && (*history_in = 2))
		do_move(*cur, readline);
	else if (move == up)
		return (move_up(cur, readline));
	else if (move == down)
	{
		int ret = move_down(cur, readline);
		(!ret) ? (*history_in = 1) : 1;
		return (ret);
	}
	return (1);
}