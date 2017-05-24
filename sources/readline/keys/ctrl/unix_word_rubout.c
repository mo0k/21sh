/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_word_rubout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 03:30:52 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/25 01:29:10 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	unix_word_rubout(t_editline *editline, t_history *history) //voir paste error & error this fct
{
	int start;
	int	state;
	char *temp;
	char *ptr1;
	char *ptr2;
	if (!editline || !history)
		return (0);
	if (!editline->pos || !*editline->temp)
	{
		ft_putchar(7);
		return (0);
	}
	if (editline->strcpy)
 	{
 		free(editline->strcpy);
 		editline->strcpy = NULL;
	}
 	state = 0;
	start = editline->pos;
	//find_start
	while (start)
	{
		if ((*(*editline->temp + start) == ' ' || *(*editline->temp + start) == '\t') && state)
		{
			//state = 2;
			start++;
			break;
		}
		else if ((*(*editline->temp + start) != ' ' || *(*editline->temp + start) != '\t'))
		{
			state = 1;
		}
		start--;
	}
	//do_back
	if (!(editline->strcpy = ft_strsub(*editline->temp, start, editline->pos - start)))
		return (1);

	if (!(editline->pos -= (int)ft_strlen(editline->strcpy)))
	{
		if (!(temp = ft_strdup(*editline->temp + (int)ft_strlen(editline->strcpy))))
			return (0);
		free(*editline->temp);
		*editline->temp = temp;
	}
	else
	{
		if (!(ptr1 = ft_strsub(*editline->temp, 0, editline->pos)))
			return (0);
		if (!(ptr2 = ft_strdup(*editline->temp + editline->pos + (int)ft_strlen(editline->strcpy))))
		{
			free(ptr1);
			return (0);
		}
		free(*editline->temp);
		if (!(*editline->temp = ft_strjoin(ptr1, ptr2)))
		{
			free(ptr1);
			free(ptr2);
			return (0);
		}
		free(ptr1);
		free(ptr2);
	}
	//do_front
	tputs(tgoto(tgetstr("LE", NULL), 1, editline->pos + (int)ft_strlen(editline->strcpy)), AFFCNT, &my_putchar);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	padding_limit(editline->pos, stock_data(NULL)->prompt.len, stock_data(NULL)->win.col);
	editline->cut = key_w;
	if (history->ret && history->history_cur)
		((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
	return (1);
}