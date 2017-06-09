/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 23:07:01 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/09 11:30:00 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

int		create_token(t_list **atoken, char *line, t_types type)
{
	printf("CREATION TOKEN:line:%s|\ntype:%s\n", line, get_token_str(type));
	t_token_elem content;

	if (!atoken || !line)
		return (0);
	init_token(&content, line, type);
	ft_lstadd_end(atoken, ft_lstnew(&content, sizeof(t_token_elem)));
	return (1);
}

t_types	get_token_type(char *symbol)
{
	t_types type;

	type = -1;
	if (!symbol)
		return (type);
	printf("symbol:%s\n", symbol);
	!ft_strcmp(symbol, ";") ? (type = SEPARATOR_OP) : 0;
	!ft_strcmp(symbol, "|") ? (type = PIPELINE) : 0;
	!ft_strcmp(symbol, "<") ? (type = REDIR_OP) : 0;
	!ft_strcmp(symbol, ">") ? (type = REDIR_OP) : 0;
	!ft_strcmp(symbol, "<<") ? (type = REDIR_OP) : 0;
	!ft_strcmp(symbol, ">>") ? (type = REDIR_OP) : 0;
	!ft_strcmp(symbol, "<&") ? (type = REDIR_OP) : 0;
	!ft_strcmp(symbol, ">&") ? (type = REDIR_OP) : 0;
	!ft_strcmp(symbol, "io_number") ? (type = IO_NUMBER) : 0;

	return (type);
}

char *get_token_str(t_types type)
{
	if (type == WORD)
		return ("WORD");
	else if (type == SEPARATOR_OP)
		return ("SEPARATOR_OP");
	else if (type == REDIR_OP)
		return ("REDIR_OP");
	else if (type == IO_NUMBER)
		return ("IO_NUMBER");
	else if (type == PIPELINE)
		return ("PIPELINE");
	return (NULL);
}