/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:44:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/09 22:07:16 by mo0ky            ###   ########.fr       */
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
	readline->in_newline = 0;
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

static void		print_catch_newline(char *begin, char *end)
{
	if (!begin || !end)
		return ;
	*end = 0;
	ft_putstr(begin);
	write(1, " ", 1);
	*end = '\n';
	begin = ++end;
	while ((end = ft_strchr(end, '\n')))
	{
		*end = 0;
		ft_putstr(begin);
		write(1, " ", 1);
		*end = '\n';
		begin = ++end;
	}
	ft_putstr(begin);
}

void	print_line(char *line, int in_newline)
{
	char *ptr_end;
	char *ptr_begin;

	if (!line)
		return ;
	ptr_begin = line;
	ptr_end = line;
	if (!in_newline && !(ptr_end = ft_strchr(line, '\n')))
		ft_putstr(line);
	else
		print_catch_newline(ptr_begin, ptr_end);
}

void	padding_limit(int pos, int len_prompt, int col)
{
	 if ((pos + len_prompt) % col == 0)
	{
		my_putc(' ');
		tputs(tgetstr("le", NULL), AFFCNT, &my_putc);
	}
}


