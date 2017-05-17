/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:11:11 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/17 05:42:35 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

int	k_delete(char **line, int *pos, t_history *history)
{
	tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	(*pos)--;
	delchar(line, *pos);
	if (*line && *(*line + *pos) != 0)
	{
		ft_putstr(*line + *pos);
		tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(*line + *pos)), AFFCNT, &my_putchar);
	}
	if (history->ret && history->history_cur)
		((t_history_elem*)(history->history_cur->content))->flag_modif = 1;
	return (1);
}

int	k_suppr(char **line, int pos, t_history *history, int len_prompt)
{
	if (ft_strlen(*line) > (stock_data(NULL)->winsize).col - len_prompt > 0)
	{
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		ft_putstr(*line + pos);
		tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(*line + pos)), AFFCNT, &my_putchar);
		return (1);
	}
	tputs(tgetstr("dc", NULL), AFFCNT, &my_putchar);
	delchar(line, pos);
	if (history->ret && history->history_cur)
		((t_history_elem*)(history->history_cur->content))->flag_modif = 1;
	return (1);
}