/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:03:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/14 15:22:40 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

int	is_special_char(char c)
{
	if (c == ';' || c == '|' || c == '<' || c == '>')// || c == '\'' || c == '\"')
		return (1);
	else
		return (0);
}

static int analyze_block(t_tokenizer *tokenizer, char *line)
{
	char **ptr_begin;
	char **ptr_end;

	if (!tokenizer || !line)
		return (0);
	ptr_begin = &tokenizer->delimiter.begin;
	ptr_end = &tokenizer->delimiter.end;
	if (**ptr_end == ';' || **ptr_end == '|')
	{
		get_word(&tokenizer->token, ptr_begin, *ptr_end);
		char i[2];
		i[0] = **ptr_end;
		i[1] = 0;
		printf("find_word:%s\n", *ptr_begin);
		printf("create symbol\n");
		create_token(&tokenizer->token, i, get_token_type(i));
		*ptr_begin = (*ptr_end) + 1;
	}
	else if (**ptr_end == '\\')
	{
		++(*ptr_end);
	}
	else if (**ptr_end == '\'' || **ptr_end == '\"')
	{
		++(*ptr_end);
		printf("Gestion des quotes\n");
		while (**ptr_end && **ptr_end != '\'' && **ptr_end != '\"')
		{
			printf("increment:%c\t%d\n", **ptr_end, **ptr_end);
			++(*ptr_end);
		}
		printf("*ptr_end:%c\t%d\n", **ptr_end, **ptr_end);
		//get_quoting_word(tokenizer, ptr_begin, ptr_end);
	}
	else if (**ptr_end == '<' || **ptr_end == '>')
		get_redirect(tokenizer, line);
	printf("DEBUG | END analyze_block\n");
	return (1);
}

int		tokenizer(t_tokenizer *tokenizer, char *line)
{
	if (!tokenizer || !line)
	{
		printf("returm;\n");
		return (0);
	}
	tokenizer->delimiter.begin = line;
	tokenizer->delimiter.end = line;
	printf("line:%s\n", line);
	while(*tokenizer->delimiter.end)
	{
		if (is_special_char(*tokenizer->delimiter.end) || *tokenizer->delimiter.end == '\'' || *tokenizer->delimiter.end == '\"' || *tokenizer->delimiter.end == '\\')
		{
			analyze_block(tokenizer, line);
		}
		printf("DEBUG | while tokenizer avant increment:%p\t%c\t%d\n", tokenizer->delimiter.end, *tokenizer->delimiter.end, *tokenizer->delimiter.end);
		if (*tokenizer->delimiter.end)
			tokenizer->delimiter.end++;
	}
	printf("DEBUG | end aavnt get word\n");
	get_word(&tokenizer->token, &tokenizer->delimiter.begin, tokenizer->delimiter.end);
	ft_lstiter(tokenizer->token, &print_token);
	return (1);
}
