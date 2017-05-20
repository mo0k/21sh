/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 05:21:35 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/20 12:21:33 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <keyboard.h>

int is_alt_keys(char *buff, char *line, int *pos)
{
	if (!buff)
		return (0);
	if (K_ALT_RIGHT(buff))
		return (k_alt_right(pos, line));
	else if (*pos > 0 && K_ALT_LEFT(buff))
		return (k_alt_left(pos, line));
	else if (K_ALT_UP(buff))
		return (k_alt_up(pos, line));
	else if (K_ALT_DOWN(buff))
		return (k_alt_down(pos, line));
	return (0);
}

int is_arrow_keys(char *buff, t_editline *editline, t_history *h)
{
	if (!buff)
		return (0);
	if (editline->pos > 0 && K_ARROW_LEFT(buff))
		return (k_arrow_left(&editline->pos));
	else if (editline->pos < (int)ft_strlen(editline->line) && K_ARROW_RIGHT(buff))
		return (k_arrow_right(&editline->pos, editline->line));
	/*
	else if (K_ARROW_UP(buff))
		return ((h->ret = move_history(&h->history_cur, &h->in, up, editline)));
	else if (K_ARROW_DOWN(buff))
	{
		if (!(h->ret = move_history(&h->history_cur, &h->in, down, editline)))
		{
			if (editline->pos > 0)
				tputs(tgoto(tgetstr("LE", NULL), 0, editline->pos),AFFCNT, &my_putchar);
			tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
			if (editline->temp == &editline->line)
				ft_putchar(7);
			editline->temp = &editline->line;
			ft_putstr(*editline->temp);
			editline->pos = ft_strlen(*editline->temp);
		}
		return (1);
	}
	*/
	return (0);
}

int is_home_or_end_keys(char *buff, char *line, int *pos)
{
	if (!buff || !line)
		return (0);
	if (*pos > 0 && K_HOME(buff))
		return (k_home(pos));
	else if (*pos < (int)ft_strlen(line) && K_END(buff))
		return (k_end(line, pos));
	return (0);
}

int is_ctrl_keys(char *buff, t_editline *editline, t_history *history)
{
	if (!buff)
		return (0);
	if (K_CTRL_Y(buff))
		return (k_ctrl_y(editline, history));
	else if (K_CTRL_U(buff))
		return (k_ctrl_u(editline, history));
	else if (K_CTRL_K(buff))
		return (k_ctrl_k(editline, history));
	else if (K_CTRL_W(buff))
		return (k_ctrl_w(editline, history));
	return (0);
}

int 	is_dels_keys(char *buff, char **line, int *pos, t_history *history)
{
	if (!buff || !line || !*line || !history)
		return (0);
	if (*pos > 0 && K_DELETE(buff))
		return (k_delete(line, pos, history));
	else if (K_BACKSPACE(buff))
		return (k_backspace(line, *pos, history, ft_strlen(stock_data(NULL)->prompt) + 3));
	return (0);
}

