/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 23:22:07 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int	do_clear(t_readline *readline)
{
	int shift;

	if (!readline)
		return (0);
	tputs(tgetstr("cl", NULL), AFFCNT, &my_putchar);
	prompt(readline->prompt.val);
	ft_putstr(*readline->temp);
	if ((int)ft_strlen(*readline->temp) > readline->pos)
	{
		shift = (int)ft_strlen(*readline->temp) - readline->pos;
		tputs(tgoto(tgetstr("LE", NULL), 1, shift), AFFCNT, &my_putchar);
	}
	padding_limit(readline->pos, readline->prompt.len, readline->win.col);
	return (1);
}