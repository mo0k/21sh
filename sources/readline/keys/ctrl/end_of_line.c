/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/20 15:05:48 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	end_of_line(char *line, int *pos)
{
	if (!line)
		return (0);
	if (*pos < (int)ft_strlen(line))
	{
		if (*pos)
			tputs(tgoto(tgetstr("LE", NULL), 1, *pos), AFFCNT, &my_putchar);
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		ft_putstr(line);
		//tputs(tgoto(tgetstr("RI", NULL), 1, ft_strlen(line) - *pos), AFFCNT, &my_putchar);
		*pos = ft_strlen(line);
		//printf("pos:%d, cols:%d\n", *pos, (int)(stock_data(NULL)->winsize).col);
		if ((*pos + (int)ft_strlen(stock_data(NULL)->prompt) + 3) % (int)(stock_data(NULL)->winsize).col == 0)
			{
				//printf("par la\n");
				my_putchar(' ');
				tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
			}
	}
	return (1);
}
