/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:28:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/24 22:56:56 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>

static int	do_move(t_list *h, t_editline *editline, int len_prompt, int col)
{
	if (editline->pos > 0)
		tputs(tgoto(tgetstr("LE", NULL), 0, editline->pos), AFFCNT, &my_putchar);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(((t_history_elem*)((h)->content))->value);
	editline->temp = &((t_history_elem*)((h)->content))->value;
	(editline->pos) = ft_strlen(*editline->temp);
	padding_limit(editline->pos, len_prompt, col);
	return (1);
}

static int 	move_up(t_list **h, t_editline *editline, int len_prompt, int col)
{
	if (!h ||!*h || !editline)
		return (0); 
	if ((*h)->prev)
	{
		*h = (*h)->prev;
		return (do_move(*h, editline, len_prompt, col));
	}
	else
	{
		ft_putchar(7);
		return(1);
	}
}

static int 	move_down(t_list **h, t_editline *editline, int len_prompt, int col)
{
	if (!h || !*h || !editline)
		return (0);
	if (*h && (*h)->next)
	{
		*h = (*h)->next;
		return (do_move(*h, editline, len_prompt, col));

	}
	else
		return (0);
}

static		int check_var(t_list **alst, t_editline *editline, int *flag_in)
{
	if (!alst || !*alst || !editline || !flag_in)
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
int 		move_history(t_shell *sh, enum e_move move)
{
	t_list		**cur;
	int			*history_in;
	t_editline	*editline;

	if (!sh)
		return (0);
	cur = &sh->history.history_cur;
	history_in = &sh->history.in;
	editline = &sh->editline;
	if (!check_var(cur, editline, history_in))
		return (0);
	if (*history_in == 1 && move == up && (*history_in = 2))
		do_move(*cur, editline, sh->prompt.len, sh->win.col);
	else if (move == up)
		return (move_up(cur, editline, sh->prompt.len, sh->win.col));
	else if (move == down)
	{

		int ret = move_down(cur, editline, sh->prompt.len, sh->win.col);
		(!ret) ? (*history_in = 1) : 1;
		return (ret);
	}
	return (1);
}