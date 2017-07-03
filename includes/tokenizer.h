/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:10:54 by mo0ky             #+#    #+#             */
/*   Updated: 2017/07/03 12:45:33 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <libft.h>
# include <ft_types.h>
#include 	<stdio.h>

void			init_tokenizer(t_tokenizer *tokenizer);
int				tokenizer(t_tokenizer *tokenizer, char *line);
int				is_special_char(char c);
void			delete_tokens(t_list **tokens);
void			init_token(t_token *e, char *val, t_token_types type);
void			delete_token(void* content, size_t size);
void			print_token(t_list *elem);
int				create_token(t_list **atoken, char *line, t_token_types type);
t_token_types	get_token_type(char *symbol);
char 			*get_token_str(t_token_types type);
int				is_io_number(char *ptr_begin, char *ptr_end);
void			get_io_number(t_list **tokens, char **begin, char *end);
void 			get_word(t_list **atoken ,char **begin, char *end);
int				get_quoting_word(t_tokenizer *tknizer, char **ptr_begin, char **ptr_end);
void			get_redirect(t_tokenizer *tokenizer, char *line);

#endif
