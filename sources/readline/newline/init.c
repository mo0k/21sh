/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:21:02 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/18 13:55:08 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <newline.h>

void	init_newline(t_readline *readline)
{
	if (!readline)
		exit(EXIT_FAILURE);
	printf("DEBUG | BEGIN init_newline\n");
	readline->line = 0;
	readline->temp = 0;
	readline->strcpy = 0;
	readline->pos = 0;
	readline->cut = 0;
	readline->prompt.val = PROMPT_NEWLINE;
	readline->prompt.len  = ft_strlen(PROMPT_NEWLINE);
	init_winsize(&readline->win, tgetnum("li"), tgetnum("co"));
	readline->in_newline = 1;
	printf("DEBUG | END init_newline\n");
}
/*
int 	getn_newline(const char *line)
{
	char *ptr;
	int i;

	i = 0;
	if (!line)
		return (0);
	ptr = (char*)line;
	while ((ptr = ft_strchr(ptr, '\n')))
	{
		i++;
		ptr++;
	}
	return (i);
}*/