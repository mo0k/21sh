/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_arrow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:49:54 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/06 23:41:06 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

int 	key_arrow_right(int *pos)
{
	tputs(tgetstr("nd", NULL), AFFCNT, &my_putchar);
	(*pos)++;
	return (1);
}
int 	key_arrow_left(int *pos)
{
	tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
	(*pos)--;
	return (1);
}
int 	key_arrow_home(int *pos)
{
	tputs(tgoto(tgetstr("LE", NULL), 1, *pos), AFFCNT, &my_putchar);
	*pos = 0;
	return (1);
}
int 	key_arrow_end(char *line, int *pos)
{
	if (!line)
		return (0);
	tputs(tgoto(tgetstr("RI", NULL), 1, ft_strlen(line) - *pos), AFFCNT, &my_putchar);
	*pos = ft_strlen(line);
	return (1);
}