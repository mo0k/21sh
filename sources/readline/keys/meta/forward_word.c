/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/20 15:08:04 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	forward_word(char *line, int *pos)
{
	char	*ptr;
	int		state;

	state = 0;
	if (*pos < 0 || !*(line + *pos))
		return (1);
	ptr = line + *pos + 1;
	while (*ptr)
	{
		if (*ptr != ' ' && *ptr != '\t' && *ptr != '\v')
			state = 1;
		else if (state && (*ptr == ' ' || *ptr == '\t' || *ptr == '\v'))
		{
			tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
			ft_putstr(line + *pos);
			tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(line + *pos) - ((ptr - 1) - (line + *pos))), AFFCNT, &my_putchar);
			*pos += (ptr - 1) - (line + *pos);
			return (1);
		}
		ptr++;
	}
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(line + *pos);
	*pos += ptr - (line + *pos);
	if ((*pos + (int)ft_strlen(stock_data(NULL)->prompt) + 3) % (int)(stock_data(NULL)->winsize).col == 0)
			{
				//printf("par la\n");
				my_putchar(' ');
				tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
			}
	return (1);
}
