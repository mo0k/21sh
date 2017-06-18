/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:28:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/17 22:52:03 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>

static int	do_move(t_list *h, t_readline *r)
{
	//char *ptr_end;
	//char *ptr_begin;

	if (r->pos > 0)
		tputs(tgoto(tgetstr("LE", NULL), 0, r->pos), AFFCNT, &my_putc);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putc);

	print_line(((t_history_elem*)((h)->content))->val, r->in_newline);

	/*ptr_begin = ((t_history_elem*)((h)->content))->value;
	ptr_end = ((t_history_elem*)((h)->content))->value;
	if (!(ptr_end = ft_strchr(ptr_end, '\n')))
		ft_putstr(((t_history_elem*)((h)->content))->value);
	else
	{
		print_catch_newline(ptr_begin, ptr_end)
		*ptr_end = 0;
		ft_putstr(ptr_begin);
		write(1, " ", 1);
		*ptr_end = '\n';
		ptr_begin = ++ptr_end;
		while ((ptr_end = ft_strchr(ptr_end, '\n')))
		{
			*ptr_end = 0;
			ft_putstr(ptr_begin);
			write(1, " ", 1);
			*ptr_end = '\n';
			ptr_begin = ++ptr_end;
		}
		ft_putstr(ptr_begin);
	}*/
	r->temp = &((t_history_elem*)((h)->content))->val;
	(r->pos) = ft_strlen(*r->temp);
	padding_limit(r->pos, r->prompt.len, r->win.col);
 	return (1);
}
/*
static int	do_move(t_list *h, t_readline *r)
{
	if (r->pos > 0)
		tputs(tgoto(tgetstr("LE", NULL), 0, r->pos), AFFCNT, &my_putc);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putc);
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
		tputs(tgoto(tgetstr("LE", NULL), 0, i), AFFCNT, &my_putc);
	tputs(tgoto(tgetstr("UP", NULL), 0, nbr_newline), AFFCNT, &my_putc);
	tputs(tgoto(tgetstr("RI", NULL), 0, r->prompt.len), AFFCNT, &my_putc);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putc);
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
	if (!h ||!*h || !readline)
		return (0); 
	if ((*h)->prev)
	{
		////printf("number of \\n:%d\n", getn_newline(((t_history_elem*)((*h)->content))->value));
		//nbr_newline = getn_newline(*readline->temp);
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
			//nbr_newline = getn_newline(*readline->temp);
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
	//printf("DEBUG | BEGIN move_history\n");
	t_list		**cur;
	int			*history_in;

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
		//nbr_newline = getn_newline(*readline->temp);
		//printf("DEBUG | after getn_newline => nbr_newline: %d\n", nbr_newline);
		do_move(*cur, readline);
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