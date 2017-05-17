/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 22:01:19 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/16 22:10:49 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

int 	k_end(char *line, int *pos)
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
