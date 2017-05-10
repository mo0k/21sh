/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:44:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/06 22:18:59 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <editline.h>

void	init_line(t_editline *editline)
{
	editline->line = 0;
	editline->temp = 0;
	editline->pos = 0;
}

void	reset_line(char **line, int *pos)
{
	if (!line || !pos)
		return;
	free(*line);
	*line = NULL;
	*pos = 0;
}