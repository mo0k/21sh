/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 03:30:52 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/17 04:28:38 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>


int 	k_ctrl_w(t_editline *editline, t_history *history)
{
	int start;
	int	state;
	char *temp;
	char *ptr1;
	char *ptr2;

	if (!editline->pos || !*editline->temp)
	{
		ft_putchar(7);
		return (1);
	}
	if (editline->strcpy)
 	 	free(editline->strcpy);
 	state = 0;
	start = editline->pos;
	while (start)
	{
		if ((*(*editline->temp + start) == ' ' || *(*editline->temp + start) == '\t') && state)
		{
			state = 2;
			start++;
			break;
		}
		else if ((*(*editline->temp + start) != ' ' || *(*editline->temp + start) != '\t'))
		{
			state = 1;
		}
		start--;
	}
	if (!(editline->strcpy = ft_strsub(*editline->temp, start, editline->pos - start)))
		return (1);
	if (!(editline->pos -= (int)ft_strlen(editline->strcpy)))
	{
		if (!(temp = ft_strdup(*editline->temp + (int)ft_strlen(editline->strcpy))))
			return (1);
		free(*editline->temp);
		*editline->temp = temp;
	}
	else
	{
		if (!(ptr1 = ft_strsub(*editline->temp, 0, editline->pos)))
			return (1);
		if (!(ptr2 = ft_strdup(*editline->temp + editline->pos + (int)ft_strlen(editline->strcpy))))
		{
			free(ptr1);
			return (1);
		}
		free(*editline->temp);
		if (!(*editline->temp = ft_strjoin(ptr1, ptr2)))
		{
			free(ptr1);
			free(ptr2);
			return (1);
		}
		free(ptr1);
		free(ptr2);
	}
	tputs(tgoto(tgetstr("LE", NULL), 1, editline->pos + (int)ft_strlen(editline->strcpy)), AFFCNT, &my_putchar);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(*editline->temp);
	tputs(tgoto(tgetstr("LE", NULL), 1, (int)ft_strlen(*editline->temp) - start), AFFCNT, &my_putchar);
	editline->cut = key_w;
	if (history->ret && history->history_cur)
		((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
	return (1);
}