/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 01:09:55 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int	do_clear(t_editline *editline, char *prompt_val, int prompt_len, int col)
{
	int shift;

	if (!editline)
		return (0);
	tputs(tgetstr("cl", NULL), AFFCNT, &my_putchar);
	prompt(prompt_val);
	ft_putstr(*editline->temp);
	if ((int)ft_strlen(*editline->temp) > editline->pos)
	{
		shift = (int)ft_strlen(*editline->temp) - editline->pos;
		tputs(tgoto(tgetstr("LE", NULL), 1, shift), AFFCNT, &my_putchar);
	}
	padding_limit(editline->pos, prompt_len, col);
	return (1);
}