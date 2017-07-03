/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 23:07:01 by mo0ky             #+#    #+#             */
/*   Updated: 2017/07/03 13:16:46 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
**	méta-caractère
**	Un caractère qui, non protégé, sépare les mots. Un de ceux-ci : 
**	| & ; ( ) < > espace tabulation
**
**	opérateur de contrôle
**	Un jeton ayant une fonction de contrôle. L'un des symboles suivants :
**	|| & && ; ;; ( ) | <retour-chariot>
**
*/

#include <tokenizer.h>

int				create_token(t_list **atoken, char *line, t_token_types type)
{
	printf("CREATION TOKEN:line:%s|\ntype:%s\n", line, get_token_str(type));
	t_token content;

	if (!atoken || !line)
		return (0);
	init_token(&content, line, type);
	ft_lstadd_end(atoken, ft_lstnew(&content, sizeof(t_token)));
	return (1);
}

t_token_types	get_token_type(char *symbol)
{
	t_token_types type;

	type = -1;
	if (!symbol)
		return (type);
	!ft_strcmp(symbol, ";") ? (type = CTRL_OP) : 0;
	!ft_strcmp(symbol, "&") ? (type = CTRL_OP) : 0;
	!ft_strcmp(symbol, "|") ? (type = CTRL_OP) : 0;
	!ft_strcmp(symbol, "<") ? (type = REDIR_OP) : 0;
	!ft_strcmp(symbol, ">") ? (type = REDIR_OP) : 0;
	!ft_strcmp(symbol, "io_number") ? (type = IO_NUMBER) : 0;
	return (type);
}

char		*get_token_str(t_token_types type)
{
	if (type == WORD)
		return ("WORD");
	else if (type == CTRL_OP)
		return ("CONTROL_OP");
	else if (type == REDIR_OP)
		return ("REDIR_OP");
	else if (type == IO_NUMBER)
		return ("IO_NUMBER");
	else if (type == PIPELINE)
		return ("PIPELINE");
	return (NULL);
}