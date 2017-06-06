/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_word_rubout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 03:30:52 by jmoucade          #+#    #+#             */
/*   Updated: 2017/06/05 15:16:45 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	unix_word_rubout(t_readline *readline, t_history *history) //voir paste error & error this fct
{
	int start;
	int	state;
	char *temp;
	char *ptr1;
	char *ptr2;
	if (!readline)
		return (0);
	if (!readline->pos || !*readline->temp)
	{
		ft_putchar(7);
		return (0);
	}
	if (readline->strcpy)
 	{
 		free(readline->strcpy);
 		readline->strcpy = NULL;
	}
 	state = 0;
	start = readline->pos;
	//find_start
	while (start)
	{
		if ((*(*readline->temp + start) == ' ' || *(*readline->temp + start) == '\t') && state)
		{
			//state = 2;
			start++;
			break;
		}
		else if ((*(*readline->temp + start) != ' ' || *(*readline->temp + start) != '\t'))
		{
			state = 1;
		}
		start--;
	}
	//do_back
	if (!(readline->strcpy = ft_strsub(*readline->temp, start, readline->pos - start)))
		return (1);

	if (!(readline->pos -= (int)ft_strlen(readline->strcpy)))
	{
		if (!(temp = ft_strdup(*readline->temp + (int)ft_strlen(readline->strcpy))))
			return (0);
		free(*readline->temp);
		*readline->temp = temp;
	}
	else
	{
		if (!(ptr1 = ft_strsub(*readline->temp, 0, readline->pos)))
			return (0);
		if (!(ptr2 = ft_strdup(*readline->temp + readline->pos + (int)ft_strlen(readline->strcpy))))
		{
			free(ptr1);
			return (0);
		}
		free(*readline->temp);
		if (!(*readline->temp = ft_strjoin(ptr1, ptr2)))
		{
			free(ptr1);
			free(ptr2);
			return (0);
		}
		free(ptr1);
		free(ptr2);
	}
	//do_front
	tputs(tgoto(tgetstr("LE", NULL), 1, readline->pos + (int)ft_strlen(readline->strcpy)), AFFCNT, &my_putc);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putc);
	padding_limit(readline->pos, readline->prompt.len, readline->win.col);
	readline->cut = key_w;
	if (history && history->ret && history->history_cur)
		((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
	return (1);
}