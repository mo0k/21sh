/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:03:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/18 17:41:49 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

void	print_token(t_list *elem)
{
	char 	*type;
	char	*val;

	if (!elem)
		return ;
	val = ((t_token*)(elem->content))->val;
	type = get_token_str(((t_token*)(elem->content))->type);
	ft_putendlcolor("----------TOKEN----------", C_YELLOW);
	printf("val:%s\ntype:%s\n", val, type);
	ft_putendlcolor("-------------------------", C_YELLOW);
}
