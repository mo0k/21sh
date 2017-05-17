/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_k.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 03:31:06 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/17 04:29:12 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

int 	k_ctrl_k(t_editline *editline, t_history *history)
{
	char *temp;
	int len;

	len = ft_strlen(*editline->temp);
	if (editline->strcpy)
		free(editline->strcpy);
	if (!(editline->strcpy = ft_strsub(*editline->temp, editline->pos, len)))
		return (1);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	if (!(temp = ft_strsub(*editline->temp, 0, editline->pos)))
		return (1);
	free(*editline->temp);
	if (!(*editline->temp = ft_strdup(temp)))
	{
		free(temp);
		return (1);
	}
	free(temp);
	if (history->ret && history->history_cur)
		((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
	editline->cut = key_k;
	return (1);
}
