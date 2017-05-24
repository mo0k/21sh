/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 03:31:06 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/25 01:10:58 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	kill_line(t_editline *editline, t_history *history)
{
	char *temp;
	int len;

	if (!editline || !history)
		return (0);
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
