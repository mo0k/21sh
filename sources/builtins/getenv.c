/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:16:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/17 16:26:54 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

char		*ft_getenv(t_list *env, char *key)
{
	t_param *param;

	if (!env || !key)
		return (NULL);
	while (env)
	{
		param = (t_param*)(env->content);
		if (!ft_strcmp(param->key, key))
			return (param->val);
		env = env->next;
	}
	return (NULL);
}