/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/24 22:57:49 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	end_of_line(t_editline *editline, int len_prompt, int col)
{
	char	*line;
	int		*pos;

	if (!editline)
		return 0;
	line = *editline->temp;
	pos = &editline->pos;
	if (!line)
		return (0);
	if (*pos < (int)ft_strlen(line))
	{
		if (*pos)
			tputs(tgoto(tgetstr("LE", NULL), 1, *pos), AFFCNT, &my_putchar);
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		ft_putstr(line);
		*pos = ft_strlen(line);
		padding_limit(*pos, len_prompt, col);
	}
	return (1);
}
