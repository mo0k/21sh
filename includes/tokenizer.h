/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:10:54 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/09 10:14:19 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <libft.h>
# include <ft_types.h>
#include 	<stdio.h>

void	init_tokenizer(t_tokenizer *tokenizer);
int		tokenizer(t_tokenizer *tokenizer, char *line);
int		is_special_char(char c);
void	delete_tokens(t_list **tokens);
void	init_token(t_token_elem *e, char *val, t_types type);
void	delete_token(void* content, size_t size);
void	print_token(t_list *elem);
int		create_token(t_list **atoken, char *line, t_types type);
t_types	get_token_type(char *symbol);
char 	*get_token_str(t_types type);
int		is_io_number(char *ptr_begin, char *ptr_end);
void	get_io_number(t_list **tokens, char **begin, char *end);
void 	get_word(t_list **atoken ,char **begin, char *end);
int		get_quoting_word(t_tokenizer *tknizer, char **ptr_begin, char **ptr_end);
void	get_redirect(t_tokenizer *tokenizer, char *line);

#endif
