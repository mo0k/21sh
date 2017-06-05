/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/05 10:23:18 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	backward_char(t_pos *cursor)
{
	if (!cursor)
		return (0);
	if (cursor->x > 0)
	{
		tputs(tgetstr("le", NULL), AFFCNT, &my_putc);
		(cursor->x)--;
	}
	return (1);
}