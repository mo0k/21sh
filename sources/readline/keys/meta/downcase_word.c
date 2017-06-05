/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   downcase_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/02 17:02:39 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int	downcase_word(t_readline *readline, t_history *history)
{
	char *ptr;
	int state;
 	char *line;
 	int *pos;

	if (!readline)
		return (0);
	line = *readline->temp;
	pos = &readline->pos;
	if (!line)
		return (0);
	state = 0;
	ptr = line + *pos;
	while (*ptr)
	{
		if (*ptr != ' ' && *ptr != '\t' && *ptr != '\v')
		{
			state = 1;
			*ptr = ft_tolower(*ptr);
		}
		else if (state && (*ptr == ' ' || *ptr == '\t' || *ptr == '\v'))
		{
			tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
			ft_putstr(line + *pos);
			//error
			*pos += (ptr) - (line + *pos);
			if ((int)ft_strlen(line) > *pos)
				tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(line + *pos) - ((ptr) - (line + *pos))), AFFCNT, &my_putchar);
			if (history && history->ret && history->history_cur)
				((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
			return (1);
		}
		ptr++;
	}
	if (state)
	{
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		ft_putstr(line + *pos);
		*pos += (ptr) - (line + *pos);
		if ((int)ft_strlen(line) > *pos)
			tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(line + *pos) - ((ptr) - (line + *pos))), AFFCNT, &my_putchar);
		if (history && history->ret && history->history_cur)
			((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
	}
	return (1);
}
