/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/20 15:09:12 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	forward_char(char *line, int *pos)
{
	if (*pos < (int)ft_strlen(line))
	{
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		ft_putstr(line + *pos);
		(*pos)++;
		if (*(line + *pos) != 0)
			tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(line + *pos)), AFFCNT, &my_putchar);
		if ((*pos + (int)ft_strlen(stock_data(NULL)->prompt) + 3) % (int)(stock_data(NULL)->winsize).col == 0)
			{
				//printf("par la\n");
				my_putchar(' ');
				tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
			}
	}
	return (1);
}
