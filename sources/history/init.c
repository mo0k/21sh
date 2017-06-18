/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:28:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/14 22:46:01 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>

static void	catch_tab(char *value)
{
	int i;

	if (!value)
		return ;
	i = 0;
	while (value[i])
	{
		if (value[i] == '\t')
			value[i] = ' ';
		i++;
	}

}

void	init_history(t_history *history)
{
	if (!history)
		exit(EXIT_FAILURE);
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
	e->val = ft_strdup(val);
	catch_tab(e->val);
	e->save = ft_strdup(val);
	e->flag_new = f_new;
	e->flag_modif = f_modif;
}
