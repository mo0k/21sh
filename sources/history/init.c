/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:28:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/02 22:56:39 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>

void	init_history(t_history *history)
{
	history->history_root = NULL;
	load_history(&history->history_root);
	history->history_cur = history->history_root;
	history->ret = 0;
	history->in = 0;
}

void	init_elem_history(t_history_elem *e, char *val, int f_new, int f_modif)
{
	if (!e || !val)
	{
		printf("return init_e]init_elem_history\n");
		return ;
	}
	e->value = ft_strdup(val);
	e->save = ft_strdup(val);
	e->flag_new = f_new;
	e->flag_modif = f_modif;
}
