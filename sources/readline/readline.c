/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:44:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/05 15:12:52 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

void	init_readline(t_readline *readline)
{
	readline->line = 0;
	readline->temp = 0;
	readline->strcpy = 0;
	readline->pos = 0;
	readline->cut = 0;
	readline->prompt.val = getcwd(NULL, CWD);
	readline->prompt.len  = ft_strlen(readline->prompt.val) + LEN_SYMBOL;
	init_winsize(&readline->win, tgetnum("li"), tgetnum("co"));
}

void	reset_line(char **line, int *pos)
{
	if (!line || !pos)
	{
		printf("DEBUG | return reset_line\n");
		return;
	}
	free(*line);
	*line = NULL;
	*pos = 0;
	printf("DEBUG | end return reset_line\n");
}

void	padding_limit(int pos, int len_prompt, int col)
{
	 if ((pos + len_prompt) % col == 0)
	{
		my_putc(' ');
		tputs(tgetstr("le", NULL), AFFCNT, &my_putc);
	}
}


