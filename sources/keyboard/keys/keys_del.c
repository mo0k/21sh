/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:11:11 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/12 18:51:11 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

int	key_delete(char **line, int *pos, t_history *history)
{
	
	tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
	tputs(tgetstr("dc", NULL), AFFCNT, &my_putchar);
	(*pos)--;
	delchar(line, *pos);
	if (history->ret && history->history_cur)
	{
		//*line = ((t_history_elem*)(((stock_data(NULL)->history).history_cur)->content))->value;
		((t_history_elem*)(history->history_cur->content))->flag_modif = 1;
	}
	return (1);
}

int	key_suppr(char **line, int *pos, t_history *history)
{
	tputs(tgetstr("dc", NULL), AFFCNT, &my_putchar);
	delchar(line, *pos);
	if (history->ret && history->history_cur)
	{
		//*line = ((t_history_elem*)(((stock_data(NULL)->history).history_cur)->content))->value;
		((t_history_elem*)(history->history_cur->content))->flag_modif = 1;
	}
	return (1);
}