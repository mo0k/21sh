/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:29:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/05 15:16:42 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	previous_history(t_readline *readline, t_history *history)
{
	//t_readline	*readline;
	//t_history	*h;

	if (!readline || !history)
		return (0);
	//readline = &sh->readline;
	//h = &sh->history;

	return ((history->ret = move_history(readline, history, up)));
}
