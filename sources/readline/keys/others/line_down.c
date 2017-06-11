/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:32:34 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/09 19:53:40 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	line_down(t_readline *readline)
{
	char 	*line;
	int		*pos;
	int 	col;

	if (!readline)
		return (1);
	line = *readline->temp;
	pos = &readline->pos;
	if (!line)
		return (1);
	col = readline->win.col;
	if ((int)readline->prompt.len + (int)ft_strlen(line) > col - 1)
	{
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putc);
		print_line(line + *pos, readline->in_newline);
		//ft_putstr(line + *pos);
		int decalage_left;
		
		if ((int)ft_strlen((line + *pos)) > col)
		{
			decalage_left = ft_strlen((line + *pos)) - col;
			*pos += col;
			tputs(tgoto(tgetstr("LE", NULL), 1, decalage_left), AFFCNT, &my_putc);
		}
		else
		{
			decalage_left = ft_strlen((line + *pos));
			*pos += decalage_left; 
		}
		
		padding_limit(*pos, readline->prompt.len, readline->win.col);
	}
	return (1);
}
