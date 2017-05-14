/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_arrow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:49:54 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/13 11:39:33 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

int 	key_arrow_right(int *pos, char *line)
{
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(line + *pos);
	(*pos)++;
	if (*(line + *pos) != 0)
		tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(line + *pos)), AFFCNT, &my_putchar);

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
	if (*pos)
		tputs(tgoto(tgetstr("LE", NULL), 1, *pos), AFFCNT, &my_putchar);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(line);
	//tputs(tgoto(tgetstr("RI", NULL), 1, ft_strlen(line) - *pos), AFFCNT, &my_putchar);
	*pos = ft_strlen(line);
	return (1);
}