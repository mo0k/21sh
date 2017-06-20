/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/19 15:52:46 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	end_of_line(t_readline *readline)
{
	char	*line;
	int		*pos;

	if (!readline)
		return (1);
	line = *readline->temp;
	pos = &readline->pos;
	if (!line)
		return (1);
	if (*pos < (int)ft_strlen(line))
	{
		if (*pos)
			tputs(tgoto(tgetstr("LE", NULL), 1, *pos), AFFCNT, &my_putc);
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putc);
		ft_putstr(line);
		//print_line(line, readline->in_newline);
		*pos = ft_strlen(line);
		padding_limit(*pos, readline->prompt.len, readline->win.col);
	}
	return (1);
}
