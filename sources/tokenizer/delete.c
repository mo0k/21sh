/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 21:34:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/31 00:44:33 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	delete_tokens(t_list **tokens)
{
	if (!tokens)
		return ;
	while (*tokens)
	{
		ft_lstdelfirst(tokens, &delete_token);
	}
}