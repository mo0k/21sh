/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 21:34:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/17 22:53:34 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	delete_token(void* content, size_t size)
{
	(void) size;
	if (!content)
		return ;
	free(((t_token*)(content))->val);
	((t_token*)(content))->val = NULL;
	free(content);
	content = NULL;
}
