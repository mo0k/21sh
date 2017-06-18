/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 10:41:26 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/18 17:20:56 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <ft_21sh.h>

int		parser(t_list **atokens, t_params *params);
void 	heredoc(t_list **tokens);
void	expension(char **value, t_params *params);
void	tilde_expension(char **value, t_params *params);
void	param_expension(char **value, t_params *params);
int		inhibitor(char *value);
void	remove_quote(char **astr, char **aptr);
void	remove_dquote(char **astr, char **aptr);
void	remove_backslash(char **astr, char **aptr);

#endif