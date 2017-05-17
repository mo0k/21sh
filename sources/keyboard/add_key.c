/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:11:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/17 06:25:38 by jmoucade         ###   ########.fr       */
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
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(str+ ++pos);
	tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(str + pos)), AFFCNT, &my_putchar);

}

void	add_key(char c, t_history *history, t_editline *editline)
{
		//int		state;
		t_history_elem	*content;

		//tputs(tgetstr("im", NULL), AFFCNT, &my_putchar);

		my_putchar(c);
		//tputs(tgetstr("ei", NULL), AFFCNT, &my_putchar);
		if (!history->ret && !editline->line)
		{
			editline->line = ft_strnew(1);
			(*(editline->line) = c);
			//state = 0;
		}
		else
		{
			if (history->history_cur)
			{
				content = ((t_history_elem*)((history->history_cur)->content));
				content->flag_modif = 1;
			}
			(editline->pos == (int)ft_strlen(*editline->temp)) ?
			ft_addchar(editline->temp, c) : addnchar(editline->temp, c, editline->pos);
		}
		editline->pos++;
		if ((editline->pos + (int)ft_strlen(stock_data(NULL)->prompt) + 3) % (stock_data(NULL)->winsize).col== 0)
		{
			my_putchar(' ');
			tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
			}
}
