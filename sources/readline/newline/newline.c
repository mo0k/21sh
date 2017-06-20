/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 18:43:40 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/19 15:57:13 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <newline.h>

int 	get_newline(char **line, t_history *h)//, int *in_newline)
{
	printf("DEBUG | BEGIN get_newline\n");
	int chr;
	t_readline r;
	int ret;
	char *join;
	t_history_elem	*content;

	if (!line)//|| !in_newline)
		return (0);
	//*in_newline = 1;
	ret = 2;
	init_newline(&r);
	r.temp = &r.line;
	while (42)
	{
		chr = 0;
		if (ret == 2)
		{
			ft_addchar(line, '\n');
			ft_putstr(PROMPT_NEWLINE);
		}
		if (read(0, &chr, sizeof(int)) > 0)
		{
			if ((ret = readline_handler(chr, &r, 0)) == 2)
			{
				if (!*r.temp)
					ft_addchar(r.temp, '\n');
				printf("OEL\n");
				printf("DEBUG | in WHILE => newline:%s\n", *r.temp);
				if (!(join = ft_strjoin(*line, *r.temp)))
				{
					//*in_newline = 0;
					//a check free
					free(r.line);
					r.line = NULL;
					r.pos = 0;
					free(r.strcpy);
					r.strcpy = NULL;
					r.temp = &r.line;
					return (0);
				}
				printf("DEBUG | in WHILE => join:%s\n", join);
				free(*line);
				*line = join;
				free(r.line);
				r.line = NULL;
				r.pos = 0;
				//*in_newline = 0;
				r.temp = &r.line;
				if (h && h->ret)
				{
					content = ((t_history_elem*)((h->history_cur)->content));
					//history->history_cur = new;
					if (content->flag_modif == 1)
					{
						content->flag_modif = 0;
						free(content->val);
						content->val = ft_strdup(content->save);
					}
					h->in = 0;
					h->ret = 0;
				}
				return (1);
			}
		}
	}
}