/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/05 15:16:50 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	forward_word(t_readline *readline)
{
	char	*ptr;
	int		state;
	char 	*line;
	int		*pos;

	if (!readline)
		return 0;
	line = *readline->temp;
	pos = &readline->pos;
	if (!line)
		return (0);
	state = 0;
	if (*pos < 0 || !*(line + *pos))
		return (1);
	ptr = line + *pos + 1;
	while (*ptr)
	{
		if (*ptr != ' ' && *ptr != '\t' && *ptr != '\v')
			state = 1;
		else if (state && (*ptr == ' ' || *ptr == '\t' || *ptr == '\v'))
		{
			tputs(tgetstr("cd", NULL), AFFCNT, &my_putc);
			ft_putstr(line + *pos);
			tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(line + *pos) - ((ptr - 1) - (line + *pos))), AFFCNT, &my_putc);
			*pos += (ptr - 1) - (line + *pos);
			return (1);
		}
		ptr++;
	}
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putc);
	ft_putstr(line + *pos);
	*pos += ptr - (line + *pos);
	padding_limit(*pos, readline->prompt.len, readline->win.col);
	return (1);
}
