/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 01:10:48 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	forward_char(t_editline *editline, int prompt_len, int col)
{
	char	*line;
	int		*pos;
	int		shift;

	if (!editline)
		return 0;
	line = *editline->temp;
	pos = &editline->pos;
	if (*pos < (int)ft_strlen(line))
	{
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		ft_putstr(line + *pos);
		(*pos)++;
		if (*(line + *pos) != 0)
		{
			shift = ft_strlen(line + *pos);
			tputs(tgoto(tgetstr("LE", NULL), 1, shift), AFFCNT, &my_putchar);
		}
		padding_limit(*pos, prompt_len, col);
	}
	return (1);
}