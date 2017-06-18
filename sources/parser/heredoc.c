/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 22:16:22 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/18 17:20:48 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static char		*do_heredoc(char *delimiter)
{
	t_readline r;
	int chr;
	int ret;
	char *join;

	if (!delimiter)
		return (NULL);
	init_newline(&r);
	join = NULL;
	r.in_newline = 1;
	r.temp = &r.line;
	ret = 2;
	while (42)
	{
		chr = 0;
		if (ret == 2)
		{
			//ft_addchar(line, '\n');
			ft_putstr(PROMPT_NEWLINE);
		}
		if (read(0, &chr, sizeof(int)) > 0)
		{
			if ((ret = readline_handler(chr, &r, 0)) == 2)
			{
				printf("delimiter:%s\tr.line:%s\n", delimiter, r.line);
				if (!ft_strcmp(r.line, delimiter))
				{
					printf("return char *join\n");
					free(r.line);
					r.line = NULL;
					free(r.strcpy);
					r.strcpy = NULL;
					return (join);
				}
				else
				{
					if (!join)
						join = ft_strdup(r.line);
					else
					{
						char *temp;
						temp = join;
						temp = ft_str3join(join, "\n", r.line);
						free(join);
						join = temp;
					}
				}
				free(r.line);
				r.line = NULL;
				r.pos = 0;
			}
		}
	}
}
static void		replace_token(char *line, int flag,  t_list *tokens, t_list **cur)
{
	//t_list *temp;

	if (!line || !tokens || !cur || !*cur)
		return ;
	//temp = (*cur)->next;
	free(((t_token*)((*cur)->next->content))->val);
	((t_token*)((*cur)->next->content))->flag_inhibitor = flag;
	((t_token*)((*cur)->next->content))->val = line;
	if (*cur == tokens)
		ft_lstdelfirst(cur, &delete_token);
	else
		ft_lstdelnext(&(*cur)->prev, &delete_token);
	//*cur = temp;

}

void		heredoc(t_list **tokens)
{
	char	*delimiter;
	int		flag;
	t_list	*addr_token;

	if (!tokens || !*tokens)
		return ;
	addr_token = *tokens;
	while (*tokens)
	{
		if (((t_token*)((*tokens)->content))->type == REDIR_OP &&
			!ft_strcmp(((t_token*)((*tokens)->content))->val, "<<"))
		{
			delimiter = ((t_token*)((*tokens)->next->content))->val;
			flag = inhibitor(delimiter);
			replace_token(do_heredoc(delimiter), flag, addr_token, tokens);
			addr_token = *tokens;
		}
		(*tokens) = (*tokens)->next;
	}
	*tokens = addr_token;
	while((*tokens)->prev)
		(*tokens) = (*tokens)->prev;
}