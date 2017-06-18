/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 20:11:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/14 22:49:42 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parameters.h>

t_list			*import_env(char **env)
{
	t_list		*lst_env;
	t_param		param;

	lst_env = NULL;
	while (*env)
	{
		param.key = ft_strsub(*env, 0, ft_strchr(*env, '=') - *env);
		param.val = ft_strdup(ft_strchr(*env, '=') + 1);
		ft_lstadd_start(&lst_env, ft_lstnew(&param, sizeof(t_param)));
		env++;
	}
	ft_lstrev(&lst_env);
	return (lst_env);
}

char			**export_env(t_list *env)
{
	int			len;
	char		**new_env;
	int			i;
	t_list		*cur;

	len = ft_lstlen(env);
	if (!env || (len == 0))
		return (NULL);
	i = 0;
	cur = env;
	new_env = (char**)malloc(sizeof(char*) * (len + 1));
	new_env[len] = NULL;
	while (cur)
	{
		new_env[i++] = ft_str3join(((t_param*)(cur->content))->key, "=",
										((t_param*)(cur->content))->val);
		cur = cur->next;
	}
	return (new_env);
}
