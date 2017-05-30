/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:03:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/30 23:29:07 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

void	print_token(t_list *elem)
{
	char 	*type;
	char	*val;

	if (!elem)
		return ;
	val = ((t_token_elem*)(elem->content))->val;
	type = get_token_str(((t_token_elem*)(elem->content))->type);
	printf("________________________\n\tval:%s\n\ttype:%s\n________________________\n", val, type);

}
