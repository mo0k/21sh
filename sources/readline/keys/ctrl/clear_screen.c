/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/19 15:58:22 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int	do_clear(t_readline *readline)
{
	int shift;

	if (!readline)
		return (1);
	tputs(tgetstr("cl", NULL), AFFCNT, &my_putc);
	prompt(readline->prompt.val);
	ft_putstr(*readline->temp);
	if ((int)ft_strlen(*readline->temp) > readline->pos)
	{
		shift = (int)ft_strlen(*readline->temp) - readline->pos;
		tputs(tgoto(tgetstr("LE", NULL), 1, shift), AFFCNT, &my_putc);
	}
	padding_limit(readline->pos, readline->prompt.len, readline->win.col);
	return (1);
}