/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 11:01:20 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/11 13:09:03 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int check_syntax(t_list *tokens)
{
	if (((t_token_elem*)(tokens->content))->type == REDIR_OP && !tokens->next)
	{
		ft_shell_error("syntax error near unexpected token 'newline'");
		return (0);
	}
	else if (((t_token_elem*)(tokens->content))->type == PIPELINE && (!tokens->prev || !tokens->next))
	{
		ft_shell_error("syntax error near unexpected token '|'");
		return (0);
	}
	else if (((t_token_elem*)(tokens->content))->type == SEPARATOR_OP && !tokens->prev)
	{
		ft_shell_error("syntax error near unexpected token ';'");
		return (0);
	}
	return (1);

}

int		parser(t_list **atokens)
{
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
	(void)atokens;
	return (1);
}