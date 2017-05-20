/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/20 16:05:23 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int	do_clear_screen(void)
{
	tputs(tgetstr("cl", NULL), AFFCNT, &my_putchar);
	prompt(stock_data(NULL)->prompt);
	ft_putstr(*(stock_data(NULL)->editline).temp);
	if ((int)ft_strlen(*(stock_data(NULL)->editline).temp) > (stock_data(NULL)->editline).pos)
		tputs(tgoto(tgetstr("LE", NULL), 1, (int)ft_strlen(*(stock_data(NULL)->editline).temp) - (stock_data(NULL)->editline).pos), AFFCNT, &my_putchar);
		if (((stock_data(NULL)->editline).pos + (int)ft_strlen(stock_data(NULL)->prompt) + 3) % (int)(stock_data(NULL)->winsize).col == 0)
			{
				my_putchar(' ');
				tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
			}
	
	return (1);
}