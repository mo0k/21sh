/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginning_of_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/05 15:16:34 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	beginning_of_line(int *pos)
{
	if (*pos > 0)
	{
		tputs(tgoto(tgetstr("LE", NULL), 1, *pos), AFFCNT, &my_putc);
		*pos = 0;
	}
	return (1);
}
