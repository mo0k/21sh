/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:49:54 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/16 22:11:17 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

int 	k_arrow_right(int *pos, char *line)
{
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(line + *pos);
	(*pos)++;
	if (*(line + *pos) != 0)
		tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(line + *pos)), AFFCNT, &my_putchar);

	return (1);
}

int 	k_arrow_left(int *pos)
{
	tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
	(*pos)--;
	return (1);
}
