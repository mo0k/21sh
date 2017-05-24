/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:32:34 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 01:50:08 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	line_down(char *line, int *pos)
{
	if (!line)
		return (0);
	int len_prompt = stock_data(NULL)->prompt.len;
	int cols = stock_data(NULL)->win.col;
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
		padding_limit(*pos, stock_data(NULL)->prompt.len, stock_data(NULL)->win.col);
	}
	return (1);
}