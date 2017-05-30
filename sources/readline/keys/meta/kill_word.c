/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 23:21:50 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int	kill_word(t_readline *readline, t_history *history)
{
 	char	**aptr;
 	char	*ptr1;
 	char	*ptr2;
 	int		pos;
 	int		end;
 	int		state;

	if (!readline || !history)
		return (0);
	if (readline->strcpy)
	{
 	 	free(readline->strcpy);
 	 	readline->strcpy = NULL;
	}
 	aptr = readline->temp;
 	pos = readline->pos;
 	end = 0;
 	state = 0;
 	if (pos == (int)ft_strlen(*aptr))
 		return (0);
	while (*(*aptr + pos + end))
	{
		if ((*(*aptr + pos + end) == ' ' || *(*aptr + pos + end) == '\t') && state)
			break;
		else if ((*(*aptr + end + pos) != ' ' || *(*aptr + end + pos) != '\t'))
			state = 1;
		end++;
	}
	if (!(readline->strcpy = ft_strsub(*aptr, pos, end)))
		return (1);
	if (!*(*aptr + pos + end))
	{
		if (!(ptr1 = ft_strsub(*aptr, 0, pos)))
			return (0);
		free(*aptr);
		*aptr = ptr1;
	}
	else
	{
		if (!(ptr1 = ft_strsub(*aptr, 0, pos)))
			return (0);
		if (!(ptr2 = ft_strdup(*aptr + pos + (int)ft_strlen(readline->strcpy))))
		{
			free(ptr1);
			return (0);
		}
		free(*aptr);
		if (!(*aptr = ft_strjoin(ptr1, ptr2)))
		{
			free(ptr1);
			free(ptr2);
			return (0);
		}
		free(ptr1);
		free(ptr2);
	}
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(*aptr + pos);
	if (pos < (int)ft_strlen(*aptr))
		tputs(tgoto(tgetstr("LE", NULL), 1, (int)ft_strlen(*aptr + pos)), AFFCNT, &my_putchar);
	if (history->ret && history->history_cur)
		((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
	return (1);
}