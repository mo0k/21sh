/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 23:22:05 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	end_of_line(t_readline *readline)
{
	char	*line;
	int		*pos;

	if (!readline)
		return 0;
	line = *readline->temp;
	pos = &readline->pos;
	if (!line)
		return (0);
	if (*pos < (int)ft_strlen(line))
	{
		if (*pos)
			tputs(tgoto(tgetstr("LE", NULL), 1, *pos), AFFCNT, &my_putchar);
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		ft_putstr(line);
		*pos = ft_strlen(line);
		padding_limit(*pos, readline->prompt.len, readline->win.col);
	}
	return (1);
}
