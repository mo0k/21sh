/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:44:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/16 15:53:26 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <editline.h>

void	init_line(t_editline *editline)
{
	editline->line = 0;
	editline->temp = 0;
	editline->strcpy = 0;
	editline->pos = 0;
	editline->cut = 0;
}

void	reset_line(char **line, int *pos)
{
	if (!line || !pos)
		return;
	free(*line);
	*line = NULL;
	*pos = 0;
}

