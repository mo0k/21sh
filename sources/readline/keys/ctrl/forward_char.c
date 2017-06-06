/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/06 01:03:44 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	forward_char(t_readline *readline)
{
	char	*line;
	int		*pos;
	int		shift;

	if (!readline)
		return 0;
	line = *readline->temp;
	pos = &readline->pos;
	if (*pos < (int)ft_strlen(line))
	{
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putc);
		ft_putstr(line + *pos);
		(*pos)++;
		if (*(line + *pos) != 0)
		{
			shift = ft_strlen(line + *pos);
			tputs(tgoto(tgetstr("LE", NULL), 1, shift), AFFCNT, &my_putc);
		}
		padding_limit(*pos, readline->prompt.len, readline->win.col);
	}
	return (1);
}

