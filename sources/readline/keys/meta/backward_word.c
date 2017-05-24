/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 01:32:16 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	backward_word(char *line, int *pos)
{
	char *ptr;
	int state;
	int shift;
//A CHECK !line
	state = 0;
	if (!*pos || !line)
		return (0);
	ptr = line + *pos - 1;
	while (ptr != line)
	{	
		if (*ptr != ' ' && *ptr != '\t' && *ptr != '\v')
			state = 1;
		else if (state && (*ptr == ' ' || *ptr == '\t' || *ptr == '\v'))
		{
			shift = (line + *pos) - ptr - 1;
			tputs(tgoto(tgetstr("LE", NULL), 1, shift), AFFCNT, &my_putchar);
			*pos -= shift;
			return (1);
		}
		ptr--;
	}
	shift = (line + *pos) - ptr;
	tputs(tgoto(tgetstr("LE", NULL), 1, shift), AFFCNT, &my_putchar);
	*pos -= shift;
	return (1);
}
