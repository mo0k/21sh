/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 11:01:20 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/18 22:31:15 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int check_syntax(t_list *tokens)
{
	if (((t_token*)(tokens->content))->type == REDIR_OP && !tokens->next)
	{
		ft_shell_error("syntax error near unexpected token 'newline'");
		return (0);
	}
	else if (((t_token*)(tokens->content))->type == REDIR_OP &&
		tokens->next && (((t_token*)(tokens->next->content))->type != WORD))
	{
		char error[93];
		ft_strclr(error);
		ft_strcpy(error, "syntax error near unexpected token '");
		ft_strcat(error, (((t_token*)(tokens->next->content))->val));
		ft_strcat(error, "\'");
		ft_shell_error(error);
		return (0);
	}
	else if (((t_token*)(tokens->content))->type == PIPELINE && (!tokens->prev || !tokens->next))
	{
		ft_shell_error("syntax error near unexpected token '|'");
		return (0);
	}
	else if (((t_token*)(tokens->content))->type == SEPARATOR_OP && !tokens->prev)
	{
		ft_shell_error("syntax error near unexpected token ';'");
		return (0);
	}
	return (1);
}

int		parser(t_list **atokens, t_params *params)
{
	(void)params;
	t_list *tokens;

	if (!atokens || !*atokens)
		return (0);
	tokens = *atokens;
	while (tokens)
	{
		if (!check_syntax(tokens))
			return (0);
		tokens = tokens->next;
	}
	printf("check_syntax ok\n");
	heredoc(atokens);
	tokens = *atokens;
	while (tokens)
	{
		if (((t_token*)(tokens->content))->type == WORD &&
		!((t_token*)(tokens->content))->flag_inhibitor)
		{
			expension(&((t_token*)(tokens->content))->val, params);
			inhibitor(((t_token*)(tokens->content))->val);
		}
		tokens = tokens->next;
	}
	return (1);
}