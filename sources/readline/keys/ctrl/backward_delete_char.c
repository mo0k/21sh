/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward_delete_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:11:11 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 01:08:46 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int	backward_delete_char(char **line, int *pos, t_history *history)
{
	int shift;

	if (*pos <= 0 || !line || !*line || !history)
		return (0);
	tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	(*pos)--;
	ft_delchar(line, *pos);
	if (*line && *(*line + *pos) != 0)
	{
		ft_putstr(*line + *pos);
		shift = ft_strlen(*line + *pos);
		tputs(tgoto(tgetstr("LE", NULL), 1, shift), AFFCNT, &my_putchar);
	}
	if (history->ret && history->history_cur)
		((t_history_elem*)(history->history_cur->content))->flag_modif = 1;
	return (1);
}
