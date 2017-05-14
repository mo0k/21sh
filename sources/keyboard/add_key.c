/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:11:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/11 22:52:09 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

static void		addnchar(char **astr, char c, int pos)
{
	char *str;
	//printf("!! DEBUG !! 1\n");
	if (!astr || !*astr || pos < 0)
		return ;
	//printf("!! DEBUG !! 2\n");
	if (!(str = ft_strnew(ft_strlen(*astr) + 1)))
		return ;
	//printf("!! DEBUG !! 3\n");
	str = ft_strncpy(str, *astr, pos);
	//printf("!! DEBUG !! str:%s\n", str);
	str[pos] = c;
	//printf("!! DEBUG !! str:%s\n", str);
	str = ft_strcat(str, (*astr) + pos);
	//printf("!! DEBUG !! str:%s\n", str);
	free(*astr);
	*astr = str;
	tputs(tgetstr("ce", NULL), AFFCNT, &my_putchar);
	ft_putstr(str+ ++pos);
	tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(str + pos)), AFFCNT, &my_putchar);

}

void	add_key(char c, t_history *history, t_editline *editline)
{
		//int		state;
		t_history_elem	*content;

		my_putchar(c);
		if (!history->ret && !editline->line)
		{
			editline->line = ft_strnew(1);
			(*(editline->line) = c);
			//state = 0;
		}
		else
		{
			content = ((t_history_elem*)((history->history_cur)->content));
			(editline->pos == (int)ft_strlen(*editline->temp)) ?
			ft_addchar(editline->temp, c) : addnchar(editline->temp, c, editline->pos);

			//(*(*editline->temp + editline->pos) = c);
			content->flag_modif = 1;
		}
		editline->pos++;
}
