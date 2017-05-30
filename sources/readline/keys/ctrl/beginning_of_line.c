/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginning_of_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 23:22:09 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	beginning_of_line(int *pos)
{
	if (*pos > 0)
	{
		tputs(tgoto(tgetstr("LE", NULL), 1, *pos), AFFCNT, &my_putchar);
		*pos = 0;
	}
	return (1);
}
