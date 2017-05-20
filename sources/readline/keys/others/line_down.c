/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:32:34 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/20 15:44:33 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	line_down(char *line, int *pos)
{
	int len_prompt = (int)ft_strlen(stock_data(NULL)->prompt) + 3;
	int cols = (int)(stock_data(NULL)->winsize).col;
	if (len_prompt + (int)ft_strlen(line) > cols - 1)
	{
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		ft_putstr(line + *pos);
		int decalage_left;
		
		if ((int)ft_strlen((line + *pos)) > cols)
		{
			decalage_left = ft_strlen((line + *pos)) - cols;
			*pos += cols;
			tputs(tgoto(tgetstr("LE", NULL), 1, decalage_left), AFFCNT, &my_putchar);
		}
		else
		{
			decalage_left = ft_strlen((line + *pos));
			*pos += decalage_left; 
		}
			if ((*pos + (int)ft_strlen(stock_data(NULL)->prompt) + 3) % (int)(stock_data(NULL)->winsize).col == 0)
			{
				//printf("par la\n");
				my_putchar(' ');
				tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
			}
	}
	return (1);
}