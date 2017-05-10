/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:11:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/06 23:41:17 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

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
			ft_addchar(editline->temp, c) :
			(*(*editline->temp + editline->pos) = c);
			content->flag_modif = 1;
		}
		editline->pos++;
}
