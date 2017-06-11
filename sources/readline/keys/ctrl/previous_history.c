/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/09 15:02:42 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	previous_history(t_readline *readline, t_history *history)
{
	//t_readline	*readline;
	//t_history	*h;

	if (!readline || !history)
		return (1);
	//readline = &sh->readline;
	//h = &sh->history;

	return ((history->ret = move_history(readline, history, up)));
}
