/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upcase_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/24 17:43:08 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int	upcase_word(char *line, int *pos)
{
	char *ptr;
	int state;

	if (!line)
		return (0);
	state = 0;
	ptr = line + *pos;
	while (*ptr)
	{
		if (*ptr != ' ' && *ptr != '\t' && *ptr != '\v')
		{
			state = 1;
			*ptr = ft_toupper(*ptr);
		}
		else if (state && (*ptr == ' ' || *ptr == '\t' || *ptr == '\v'))
		{
			tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
			ft_putstr(line + *pos);
			//error
			*pos += (ptr) - (line + *pos);
			if ((int)ft_strlen(line) > *pos)
				tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(line + *pos) - ((ptr) - (line + *pos))), AFFCNT, &my_putchar);
			return (1);
		}
		ptr++;
		//*pos++
	}
	if (state)
	{
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		ft_putstr(line + *pos);
		*pos += (ptr) - (line + *pos);
		if ((int)ft_strlen(line) > *pos)
			tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(line + *pos) - ((ptr) - (line + *pos))), AFFCNT, &my_putchar);
	}
	//mettre en maj depuis le curseur jusqu'a fin du mot
	//printf("%s\n", );
	return (1);
}
