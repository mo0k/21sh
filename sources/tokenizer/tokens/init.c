/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:03:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/18 14:30:03 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

void	init_token(t_token *e, char *val, t_types type)
{
	if (!e)
		return ;
	e->val = ft_strtrim(val);
	e->type = type;
	e->flag_inhibitor = 0;
}