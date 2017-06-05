/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:28:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/05 09:53:16 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>

static int	do_move(t_list *h, t_readline *r, int nbr_newline)
{
	int i;
	char *ptr;

	//printf("DEBUG | BEGIN do_move\n");
	if (!h || !r)
	{
		//printf("DEBUG | retunr (0)\n");
		return (0);
	}
	if (!nbr_newline)
	{
		//printf("DEBUG | !nbr_newline\n");
		if (r->pos > 0)
			tputs(tgoto(tgetstr("LE", NULL), 0, r->pos), AFFCNT, &my_putchar);
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	}
	else
	{
		//printf("DEBUG | nbr_newline > 0\n");
		//printf("DEBUG | *r->temp:%p\n", *r->temp);
		ptr = *r->temp;
		i = ft_strlen(ptr);
		while (ptr[i] != '\n')
			--i;
		if (i > 0)
			tputs(tgoto(tgetstr("LE", NULL), 0, i), AFFCNT, &my_putchar);
		tputs(tgoto(tgetstr("UP", NULL), 0, nbr_newline), AFFCNT, &my_putchar);
		tputs(tgoto(tgetstr("RI", NULL), 0, r->prompt.len), AFFCNT, &my_putchar);
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	}
	ft_putstr(((t_history_elem*)((h)->content))->value);
	r->temp = &((t_history_elem*)((h)->content))->value;
	//error position
	(r->pos) = ft_strlen(*r->temp);
	padding_limit(r->pos, r->prompt.len, r->win.col);
	return (1);
}
/*
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

static int	do_move_bis(t_list *h, t_readline *r, int nbr_newline)
{
	(void)h;
	int i;
	char *ptr;

	i = 0;
	ptr = *r->temp;
	while (ptr[i] != '\n')
		i++;
	if (i > 0)
		tputs(tgoto(tgetstr("LE", NULL), 0, i), AFFCNT, &my_putchar);
	tputs(tgoto(tgetstr("UP", NULL), 0, nbr_newline), AFFCNT, &my_putchar);
	tputs(tgoto(tgetstr("RI", NULL), 0, r->prompt.len), AFFCNT, &my_putchar);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		i++;
	//ft_putstr(((t_history_elem*)((h)->content))->value);
	//r->temp = &((t_history_elem*)((h)->content))->value;
	//(r->pos) = ft_strlen(*r->temp);
	//padding_limit(r->pos, r->prompt.len, r->win.col);
	return (1);
}
*/
static int 	move_up(t_list **h, t_readline *readline)
{
	int nbr_newline;

	if (!h ||!*h || !readline)
		return (0); 
	if ((*h)->prev)
	{
		////printf("number of \\n:%d\n", getn_newline(((t_history_elem*)((*h)->content))->value));
		nbr_newline = getn_newline(*readline->temp);
		*h = (*h)->prev;
		return (do_move(*h, readline, nbr_newline));
	}
	else
	{
		ft_putchar(7);
		return(1);
	}
}

static int 	move_down(t_list **h, t_readline *readline)
{
	int nbr_newline;

	if (!h || !*h || !readline)
		return (0);
	if (*h && (*h)->next)
	{
			nbr_newline = getn_newline(*readline->temp);
			*h = (*h)->next;
			return (do_move(*h, readline, nbr_newline));
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
	//printf("DEBUG | BEGIN move_history\n");
	t_list		**cur;
	int			*history_in;
	int 		nbr_newline;

	if (!h || !readline)
		return (0);
	cur = &h->history_cur;
	history_in = &h->in;
	//readline = &sh->readline;
	if (!check_var(cur, readline, history_in))
		return (0);
	//printf("DEBUG | aFTER check_var\n");
	if (*history_in == 1 && move == up && (*history_in = 2))
	{
		//printf("DEBUG | fisrt choose\n");
		//readline->temp = &((t_history_elem*)((*cur)->content))->value;
		//printf("DEBUG | readline->temp:\t%p\n", *readline->temp);
		nbr_newline = getn_newline(*readline->temp);
		//printf("DEBUG | after getn_newline => nbr_newline: %d\n", nbr_newline);
		do_move(*cur, readline, nbr_newline);
	}
	else if (move == up){
		//printf("DEBUG | move == up\n");
		return (move_up(cur, readline));
	}
	else if (move == down)
	{
		//printf("DEBUG | move == up\n");
		int ret = move_down(cur, readline);
		(!ret) ? (*history_in = 1) : 1;
		return (ret);
	}
	return (1);
}