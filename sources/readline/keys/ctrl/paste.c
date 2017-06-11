/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 15:59:33 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/09 19:51:34 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

static int	cursor_max_left(char **aline, char *strcpy)
{
	char *ptr_end;

	if (!*aline)
		*aline = ft_strdup(strcpy);
	else
	{
		ptr_end = ft_strdup(*aline);
		free(*aline);
		if (!(*aline = ft_strjoin(strcpy, ptr_end)))
		{
			free(ptr_end);
			return (0);
		}
		free(ptr_end);
	}
	return (1);
}

static int	cursor_no_max_left(char **aline, char *strcpy, int position)
{
	char *ptr_start;
	char *ptr_end;

	if (!(ptr_start = ft_strsub(*aline, 0, position)))
		return (0);
	if (!(ptr_end = ft_strdup(*aline + position)))
	{
		free(ptr_start);
		return (0);
	}
	free(*aline);
	if (!(*aline = ft_str3join(ptr_start, strcpy, ptr_end)))
	{
		free(ptr_start);
		free(ptr_end);
		return (0);
	}
	free(ptr_start);
	free(ptr_end);
	return (1);
}

static int	check_go_left(char **alst, int pos, int len_line, enum e_cut cut)
{
	if ((!(!pos && (*alst && !**alst)) && cut == key_u) ||
		(cut == key_k && pos != len_line) ||
		(cut == 0 && pos != len_line))
		return (1);
	else
		return (0);
}

int 	paste(t_readline *e, t_history *history)
{
	int save_position;

	if (!e || !e->strcpy || !e->temp)
		return (1);
	save_position = e->pos;
	print_line(e->strcpy, e->in_newline);
	//ft_putstr(e->strcpy);
	if (*e->temp)
		print_line(*e->temp + e->pos, e->in_newline);
		//ft_putstr(*e->temp + e->pos);
	if (check_go_left(e->temp, e->pos, ft_strlen(*e->temp), e->cut))
		tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(*e->temp + e->pos))
					, AFFCNT, &my_putc);
	e->pos += ft_strlen(e->strcpy);
	if (save_position == 0)
	{
		if (!cursor_max_left(e->temp, e->strcpy))
			return (1);
	}
	else
		if (!(cursor_no_max_left(e->temp, e->strcpy, save_position)))
			return (1);
	e->cut = 0;
	if (history && history->ret && history->history_cur)
		((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
	padding_limit(e->pos, e->prompt.len, e->win.col);
	return (1);
}

