/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:11:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 01:49:12 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

static void		addnchar(char **astr, char c, int pos)
{
	char *str;

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
	tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(str + pos)), AFFCNT, &my_putchar);

}

void	add_key(char c, t_shell *sh)
{
		t_history 		*h;
		t_editline		*r;

		if (!sh)
			return ;
		h = &sh->history;
		r = &sh->editline;
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
		padding_limit(r->pos, sh->prompt.len, sh->win.col);
}
