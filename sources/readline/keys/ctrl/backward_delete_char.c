/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward_delete_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:11:11 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/19 15:57:30 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int	backward_delete_char(t_readline *readline, t_history *history)
{
	int		shift;
	char	**line;
	int 	*pos;

	if (!readline)
		return (1);
	line = readline->temp;
	pos = &readline->pos;
	if (*pos <= 0 || !line || !*line)
		return (1);
	tputs(tgetstr("le", NULL), AFFCNT, &my_putc);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putc);
	(*pos)--;
	ft_delchar(line, *pos);
	if (*line && *(*line + *pos) != 0)
	{
		ft_putstr(*line + *pos);
		shift = ft_strlen(*line + *pos);
		tputs(tgoto(tgetstr("LE", NULL), 1, shift), AFFCNT, &my_putc);
	}
	if (history && history->ret && history->history_cur)
		((t_history_elem*)(history->history_cur->content))->flag_modif = 1;
	return (1);
}
