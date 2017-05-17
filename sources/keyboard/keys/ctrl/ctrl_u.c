/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 03:30:58 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/17 04:30:09 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

int 	k_ctrl_u(t_editline *editline, t_history *history)
{
	char *temp;

	if (editline->strcpy)
		free(editline->strcpy);
	if (!(editline->strcpy = ft_strsub(*editline->temp, 0, editline->pos)))
		return (1);
	if (editline->pos)
		tputs(tgoto(tgetstr("LE", NULL), 1, editline->pos), AFFCNT, &my_putchar);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(*editline->temp + editline->pos);
	if (!(temp = ft_strdup(*editline->temp + editline->pos)))
		return (1);
	free(*editline->temp);
	if (!(*editline->temp = ft_strdup(temp)))
	{
		free(temp);
		return (1);
	}
	free(temp);
	editline->pos = ft_strlen(*editline->temp);
	if (editline->pos)
		tputs(tgoto(tgetstr("LE", NULL), 1, editline->pos), AFFCNT, &my_putchar);
	editline->pos = 0;
	if (history->ret && history->history_cur)
		((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
	editline->cut = key_u;
	return (1);
}
