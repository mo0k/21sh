/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/20 13:07:26 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	backward_word(char *line, int *pos)
{
	char *ptr;
	int state;

	state = 0;
	if (!*pos)
		return (1);
	ptr = line + *pos - 1;
	while (ptr != line)
	{	
		if (*ptr != ' ' && *ptr != '\t' && *ptr != '\v')
			state = 1;
		else if (state && (*ptr == ' ' || *ptr == '\t' || *ptr == '\v'))
		{
			tputs(tgoto(tgetstr("LE", NULL), 1, (line + *pos) - ptr - 1), AFFCNT, &my_putchar);
			*pos -= (line + *pos) - ptr - 1;
			return (1);
		}
		ptr--;
	}
	tputs(tgoto(tgetstr("LE", NULL), 1, (line + *pos) - ptr), AFFCNT, &my_putchar);
	*pos -= (line + *pos) - ptr;
	return (1);
}
