/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/24 22:23:15 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	previous_history(t_shell *sh)
{
	t_editline	*editline;
	t_history	*h;

	if (!sh)
		return (0);
	editline = &sh->editline;
	h = &sh->history;

	return ((h->ret = move_history(sh, up)));
}
