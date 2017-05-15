/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 15:59:33 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/15 15:15:53 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

int 	key_ctrl_y(char **line, int *pos, char **strcpy, t_history *history)
{
	char *ptr_start;
	char *ptr_end;
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	if (!strcpy || !*strcpy || !line)
		return (1);
	if (*pos == 0)
	{
		if (!*line)
		{
			*line = ft_strdup(*strcpy);
		}
		else
		{
			ptr_end = ft_strdup(*line);
			free(*line);
			if (!(*line = ft_strjoin(*strcpy, ptr_end)))
			{
				free(ptr_end);
				return (1);
			}
			free(ptr_end);
		}
		ft_putstr(*line);
		*pos = ft_strlen(*line);
	}
	else
	{
		if (!(ptr_start = ft_strsub(*line, 0, *pos)))
			return (1);
		if (!(ptr_end = ft_strdup(*line + *pos)))
		{
			free(ptr_start);
			return (1);
		}
		free(*line);
		if (!(*line = ft_str3join(ptr_start, *strcpy, ptr_end)))
		{
			free(ptr_start);
			free(ptr_end);
			return (1);
		}
		free(ptr_start);
		free(ptr_end);
		ft_putstr(*strcpy);
		*pos += ft_strlen(*strcpy);
	}
		if (history->ret)
			((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;

	return (1);
}

int 	key_ctrl_u(char **line, int *pos, char **strcpy, t_history *history)
{
	char *temp;

	if (strcpy && *strcpy)
		free(*strcpy);
	if (!(*strcpy = ft_strsub(*line, 0, *pos)))
		return (1);
	if (*pos)
		tputs(tgoto(tgetstr("LE", NULL), 1, *pos), AFFCNT, &my_putchar);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(*line + *pos);
	if (!(temp = ft_strdup(*line + *pos)))
		return (1);
	free(*line);
	if (!(*line = ft_strdup(temp)))
	{
		free(temp);
		return (1);
	}
	free(temp);
	*pos = ft_strlen(*line);
	if (*pos)
		tputs(tgoto(tgetstr("LE", NULL), 1, *pos), AFFCNT, &my_putchar);
	*pos = 0;
	if (history->ret)
		((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
	return (1);
}

int 	key_ctrl_k(char **line, int *pos, char **strcpy)
{
	(void)line;
	(void)pos;
	(void)strcpy;
	return (1);
}

int 	key_ctrl_w(char **line, int *pos, char **strcpy)
{
	(void)line;
	(void)pos;
	(void)strcpy;
	return (1);
}
