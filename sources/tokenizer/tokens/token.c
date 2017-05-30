/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 23:07:01 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/31 00:44:04 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

int		create_token(t_list **atoken, char *line, t_types type)
{
	//printf("CREATION TOKEN:line:%s|\ntype:%u\n", line, type);
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
	!ft_strcmp(symbol, ";") ? (type = separator) : 0;
	!ft_strcmp(symbol, "|") ? (type = pipes) : 0;
	!ft_strcmp(symbol, "<") ? (type = less) : 0;
	!ft_strcmp(symbol, ">") ? (type = great) : 0;
	!ft_strcmp(symbol, "<<") ? (type = dless) : 0;
	!ft_strcmp(symbol, ">>") ? (type = dgreat) : 0;
	!ft_strcmp(symbol, "<&") ? (type = lessand) : 0;
	!ft_strcmp(symbol, ">&") ? (type = greatand) : 0;
	!ft_strcmp(symbol, "io_number") ? (type = io_number) : 0;

	return (type);
}

char *get_token_str(t_types type)
{
	if (type == word)
		return ("word");
	else if (type == less)
		return ("less");
	else if (type == dless)
		return ("dless");
	else if (type == great)
		return ("great");
	else if (type == dgreat)
		return ("dgreat");
	else if (type == lessand)
		return ("lessand");
	else if (type == greatand)
		return ("greatand");
	else if (type == pipes)
		return ("pipes");
	else if (type == separator)
		return ("separator");
	else if (type == io_number)
		return ("io_number");
	return (NULL);
}