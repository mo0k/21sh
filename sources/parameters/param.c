/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 18:18:59 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/14 22:51:44 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parameters.h>

char			*get_param(t_list *params, char *key)
{
	t_list		*cur;

	cur = params;
	while (cur)
	{
		if (!ft_strcmp(key, ((t_param*)(cur->content))->key))
			return (((t_param*)(cur->content))->val);
		cur = cur->next;
	}
	return (NULL);
}

void 			print_param_all(t_list *param)
{
	if (!param)
		return ;
	ft_putstr(((t_param*)(param->content))->key);
	write(1, "=", 1);
	ft_putstr(((t_param*)(param->content))->val);
	write(1, "\n", 1);
}

void			print_param(t_list *param)
{
	ft_putstr(((t_param*)(param->content))->val);
	write(1, "\n", 1);
}