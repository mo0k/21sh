/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:11:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/02 16:04:03 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

static void		addnchar(char **astr, char c, int pos)
{
	char	*str;
	int		shift;

	if (!astr || !*astr || pos < 0)
		return ;
	if (!(str = ft_strnew(ft_strlen(*astr) + 1)))
		return ;
	str = ft_strncpy(str, *astr, pos);
	str[pos] = c;
	str = ft_strcat(str, (*astr) + pos);
	free(*astr);
	*astr = str;
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(str+ ++pos);
	shift = ft_strlen(str+pos);
	tputs(tgoto(tgetstr("LE", NULL), 1, shift), AFFCNT, &my_putchar);

}

int		add_key(char c, t_readline *r, t_history *h)
{
		if (!r)
			return (0);
		my_putchar(c);
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
				ft_addchar(r->temp, c) : addnchar(r->temp, c, r->pos);
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
				ft_addchar(r->temp, c) : addnchar(r->temp, c, r->pos);
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