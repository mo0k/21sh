/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 18:18:59 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/19 09:55:35 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parameters.h>

int				set_param(t_list **params, char *value)
{
	char		*ptr;
	t_param		param;

	if (!params || !value)
		return (0);
	if (!(ptr = ft_strchr(value, '=')))
		return (0);
	*ptr = '\0';
	param.key = ft_strdup(value);
	param.val =	ft_strdup(ptr + 1);
	*ptr = '=';
	ft_lstadd_end(params, ft_lstnew(&param, sizeof(t_param)));
	return (1);
}

char			*get_param(t_list *params, char *key)
{
	t_param *param;

	if (!key)
		return (NULL);
	while (params)
	{
		param = (t_param*)(params->content);
		if (!ft_strcmp(key, param->key))
			return (param->val);
		params = params->next;
	}
	return (NULL);
}

void 			print_all_params(t_params *params)
{
	if (!params)
		return ;
	ft_lstiter(params->environment,  print_param_all);
	ft_lstiter(params->temporary,  print_param_all);
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
