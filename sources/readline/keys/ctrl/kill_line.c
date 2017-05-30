/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 03:31:06 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/25 23:22:01 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	kill_line(t_readline *readline, t_history *history)
{
	char *temp;
	int len;

	if (!readline || !history)
		return (0);
	len = ft_strlen(*readline->temp);
	if (readline->strcpy)
		free(readline->strcpy);
	if (!(readline->strcpy = ft_strsub(*readline->temp, readline->pos, len)))
		return (1);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	if (!(temp = ft_strsub(*readline->temp, 0, readline->pos)))
		return (1);
	free(*readline->temp);
	if (!(*readline->temp = ft_strdup(temp)))
	{
		free(temp);
		return (1);
	}
	free(temp);
	if (history->ret && history->history_cur)
		((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
	readline->cut = key_k;
	return (1);
}
