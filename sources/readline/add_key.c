/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:11:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/19 16:00:00 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

static void		ft_addnchar(char **astr, char c, int pos)
{
	char	*str;
	//int		shift;

	if (!astr || !*astr || pos < 0)
		return ;
	if (!(str = ft_strnew(ft_strlen(*astr) + 1)))
		return ;
	str = ft_strncpy(str, *astr, pos);
	str[pos] = c;
	str = ft_strcat(str, (*astr) + pos);
	free(*astr);
	*astr = str;
}

static void		addnchar(t_readline *readline, char c)
{
	//char	*str;
	int		shift;
	int 	*pos;

	pos = &readline->pos;
	ft_addnchar(readline->temp, c, readline->pos);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putc);
	//print_line(*readline->temp + readline->pos + 1, readline->in_newline);
	//ft_putstr(str+ ++pos);
	ft_putstr(*readline->temp + readline->pos + 1);
	shift = ft_strlen(*readline->temp + readline->pos + 1);
	tputs(tgoto(tgetstr("LE", NULL), 1, shift), AFFCNT, &my_putc);

}

int		add_key(char c, t_readline *r, t_history *h)
{
		if (!r)
			return (0);
		my_putc(c);
		if (h)
		{
			if (!h->ret && !r->line)
			{
				r->line = ft_strnew(1);
				(*(r->line) = c);
			}
			else
			{
				if (h->history_cur && h->ret)
					((t_history_elem*)(h->history_cur->content))->flag_modif = 1;
				(r->pos == (int)ft_strlen(*r->temp)) ?
				ft_addchar(r->temp, c) : addnchar(r, c);
			}
		}
		else
		{
			if (!r->line)
			{
				r->line = ft_strnew(1);
				(*(r->line) = c);
			}
			else
			{
				(r->pos == (int)ft_strlen(*r->temp)) ?
				ft_addchar(r->temp, c) : addnchar(r, c);
			}
		}
		r->pos++;
		padding_limit(r->pos, r->prompt.len, r->win.col);
		return (1);
}
/*
int		add_key(char c, t_readline *r, t_history *h)
{
		//t_history 		*h;
		//t_readline		*r;

		if (!h || !r)
			return (0);
		//h = &sh->history;
		//r = &sh->readline;
		my_putchar(c);
		if (!h->ret && !r->line)
		{
			r->line = ft_strnew(1);
			(*(r->line) = c);
		}
		else
		{
			if (h->history_cur && h->ret)
				((t_history_elem*)(h->history_cur->content))->flag_modif = 1;
			(r->pos == (int)ft_strlen(*r->temp)) ?
			ft_addchar(r->temp, c) : addnchar(r->temp, c, r->pos);
		}
		r->pos++;
		padding_limit(r->pos, r->prompt.len, r->win.col);
		return (1);
}
*/