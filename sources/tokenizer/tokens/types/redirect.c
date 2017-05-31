/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 22:01:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/01 01:05:23 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

static void 	get_remaining_block(t_tokenizer *tokenizer, char *line)
{
	char **ptr_begin;
	char *ptr_end;

	if (!tokenizer || !line)
		return ;
	ptr_begin =  &tokenizer->delimiter.begin;
	ptr_end = tokenizer->delimiter.end;
	if (line < ptr_end && *(ptr_end - 1) == ' ')
		get_word(&tokenizer->token, ptr_begin, ptr_end - 1);
	else
		get_io_number(&tokenizer->token, ptr_begin, ptr_end);
}

static int 	is_redirect(t_tokenizer *tokenizer, char *line, char *symbol)
{
	printf("symbol:%s\nchar:%c\n", symbol, *(tokenizer->delimiter.end + 1));
	if (ft_strlen(tokenizer->delimiter.end) >= 1 &&
		*(tokenizer->delimiter.end + 1) == symbol[1])
	{
		get_remaining_block(tokenizer, line);
		create_token(&tokenizer->token, symbol, get_token_type(symbol));
		return (1);
	}
	return (0);
}

static void	redirectiong_input(t_tokenizer *tknizer, char *line)
{
	char **ptr_begin;
	char *ptr_end;

	if (!tknizer || !line)
		return ;
	ptr_begin =  &tknizer->delimiter.begin;
	ptr_end = tknizer->delimiter.end;
	if (is_redirect(tknizer, line, "<<") || is_redirect(tknizer, line, "<&"))
		tknizer->delimiter.end++;
	else
	{
		get_remaining_block(tknizer, line);
		create_token(&tknizer->token, "<", get_token_type("<"));
	}

}

static void	redirecting_oupout(t_tokenizer *tknizer, char *line)
{
	if (!tknizer || !line)
		return ;
	if (is_redirect(tknizer, line, ">>") || is_redirect(tknizer, line, ">&"))
		tknizer->delimiter.end++;
	else
	{
		get_remaining_block(tknizer, line);
		create_token(&tknizer->token, ">", get_token_type(">"));
	}
}

void	get_redirect(t_tokenizer *tokenizer, char *line)
{

	if (!tokenizer || !line)
		return ;
	if (*tokenizer->delimiter.end == '<')
		redirectiong_input(tokenizer, line);
	else
		redirecting_oupout(tokenizer, line);
	tokenizer->delimiter.begin = tokenizer->delimiter.end + 1;
}