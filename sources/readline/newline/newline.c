/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 18:43:40 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/08 14:19:24 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <newline.h>
/*
int		get_newline(char **line, t_readline *r)
{
	int chr;
	t_readline r;
	int ret;

	if (!line)
		return (0);
	ret = 2;
	chr = 0;
	init_newline(&r);
	r.temp = &r.line;
	if (ret == 2)
	{
		ft_addchar(line, '\n');
		ft_putstr(PROMPT_NEWLINE);
	}
	if (read(0, &chr, sizeof(int)) > 0)
	{
		if ((ret = newline_handler(chr, &r)) == 2)
		{
			if (!r.line)
				ft_addchar(&r.line, '\n');
			printf("OEL\n");
			printf("DEBUG | in WHILE => newline:%s\n", r.line);
			if (!(join = ft_strjoin(*line, r.line)))
			{
				//a check free
				free(r.line);
				return ;
			}
			printf("DEBUG | in WHILE => join:%s\n", join);
			free(*line);
			*line = join;
			free(r.line);
			r.line = NULL;
			r.pos = 0;
		}
	}
	retrun (1);
}
*/
int 	get_newline(char **line)
{
	printf("DEBUG | BEGIN get_newline\n");
	int chr;
	t_readline r;
	int ret;
	char *join;

	if (!line)
		return (0);
	ret = 2;
	chr = 0;
	init_newline(&r);
	r.temp = &r.line;
	while (42)
	{
		if (ret == 2)
		{
			ft_addchar(line, '\n');
			ft_putstr(PROMPT_NEWLINE);
		}
		if (read(0, &chr, sizeof(int)) > 0)
		{
			if ((ret = newline_handler(chr, &r)) == 2)
			{
				if (!r.line)
					ft_addchar(&r.line, '\n');
				printf("OEL\n");
				printf("DEBUG | in WHILE => newline:%s\n", r.line);
				if (!(join = ft_strjoin(*line, r.line)))
				{
					//a check free
					free(r.line);
					return (0);
				}
				printf("DEBUG | in WHILE => join:%s\n", join);
				free(*line);
				*line = join;
				free(r.line);
				r.line = NULL;
				r.pos = 0;
				return (1);
			}
		}
	}
	//retrun (1);
}