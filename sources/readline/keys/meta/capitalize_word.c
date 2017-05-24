/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capitalize_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 01:39:32 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int	capitalize_word(char *line, int *pos)
{
	//Majuscules sur curseur et lecture jusqu.a fin du mot pour enlever Majuscules
	char *ptr;
	int state;
	int first_char;
	int shift;

	first_char = 0;
	if (!line)
		return (0);
	state = 0;
	ptr = line + *pos;
	while (*ptr)
	{
		if (*ptr != ' ' && *ptr != '\t' && *ptr != '\v')
		{
			if (!first_char++)
				*ptr = ft_toupper(*ptr);
			else
				*ptr = ft_tolower(*ptr);
			state = 1;
		}
		else if (state && (*ptr == ' ' || *ptr == '\t' || *ptr == '\v'))
		{
			tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
			ft_putstr(line + *pos);
			//error
			*pos += (ptr) - (line + *pos);
			if ((int)ft_strlen(line) > *pos)
			{
				shift = ft_strlen(line + *pos) - ((ptr) - (line + *pos));
				tputs(tgoto(tgetstr("LE", NULL), 1, shift), AFFCNT, &my_putchar);
			}
			return (1);
		}
		ptr++;
	}
	if (state)
	{
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		ft_putstr(line + *pos);
		*pos += (ptr) - (line + *pos);
		if ((int)ft_strlen(line) > *pos)
		{
			shift = ft_strlen(line + *pos) - ((ptr) - (line + *pos));
			tputs(tgoto(tgetstr("LE", NULL), 1, shift), AFFCNT, &my_putchar);
		}
	}
	return (1);
}
