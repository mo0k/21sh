/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:32 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/15 11:13:13 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>
static 	int is_alt_keys(char *buff, char *line, int *pos)
{
	if (!buff)
		return (0);
	if (IS_K_ALT_RIGHT(buff))
	{
		return (key_alt_right(pos, line));
	}
	else if (*pos > 0 && IS_K_ALT_LEFT(buff))
	{
		return (key_alt_left(pos, line));
	}
	else if (IS_K_ALT_UP(buff))
	{
		return (key_alt_up(pos, line));
	}
	else if (IS_K_ALT_DOWN(buff))
	{
		return (key_alt_down(pos, line));
	}
	return (0);
}
static 	int is_arrow_keys(char *buff, char *line, int *pos, t_history *history,  t_editline *editline)
{
	if (!buff)
		return (0);
	if (*pos > 0 && IS_K_ARROW_LEFT(buff))
		return (key_arrow_left(pos));
	else if (*pos < (int)ft_strlen(line) && IS_K_ARROW_RIGHT(buff))
		return (key_arrow_right(pos, line));
	else if (IS_K_ARROW_UP(buff))
		return ((history->ret = move_history(&history->history_cur, &history->in, up, editline)));
	else if (IS_K_ARROW_DOWN(buff))
	{
		if (!(history->ret = move_history(&history->history_cur, &history->in, down, editline)))
		{
			if (editline->pos > 0)
				tputs(tgoto(tgetstr("LE", NULL), 0, editline->pos), AFFCNT, &my_putchar);
			tputs(tgetstr("ce", NULL), AFFCNT, &my_putchar);
			if (editline->temp == &editline->line)
				ft_putchar(7);
			editline->temp = &editline->line;
			ft_putstr(*editline->temp);
			editline->pos = ft_strlen(*editline->temp);
		}
		return (1);
	}
	return (0);
}

static 	int is_home_or_end_keys(char *buff, char *line, int *pos)
{
	if (!buff || !line)
		return (0);
	if (*pos > 0 && IS_K_HOME(buff))
		return (key_arrow_home(pos));
	else if (*pos < (int)ft_strlen(line) && IS_K_END(buff))
		return (key_arrow_end(line, pos));
	return (0);
}

static int 	is_dels_keys(char *buff, char **line, int *pos, t_history *history)
{
	if (!buff || !line || !*line || !history)
		return (0);
	if (*pos > 0 && IS_K_DELETE(buff))
	{
		//if (ft_strlen(*line) > ((stock_data(NULL)->winsize).col - ft_strlen(stock_data(NULL)->prompt) + 3) > 0)
		//{
		//	printf("PAR LAAAAAA => %lu\n", ft_strlen(*line) - ((stock_data(NULL)->winsize).col - ft_strlen(stock_data(NULL)->prompt) + 3));
		//	printf("len_line:%zu\n", ft_strlen(*line));
		//	printf("cols:%d\n", (stock_data(NULL)->winsize).col);
		//	printf("len_prompt:%zu\n", ft_strlen(stock_data(NULL)->prompt) + 3);
			tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
			tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
			//return 1;
			//ft_putstr(*line + *pos);
			//tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(*line + *pos)), AFFCNT, &my_putchar);
		//	(*pos)--;
		//	return (1);
		//}
		//tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
		//tputs(tgetstr("dc", NULL), AFFCNT, &my_putchar);
		(*pos)--;
		delchar(line, *pos);
		if (*(*line + *pos) != 0)
		{
			ft_putstr(*line + *pos);
			tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(*line + *pos)), AFFCNT, &my_putchar);
		}
		if (history->ret && history->history_cur)
		{
			//*line = ((t_history_elem*)(((stock_data(NULL)->history).history_cur)->content))->value;
			((t_history_elem*)(history->history_cur->content))->flag_modif = 1;
		}
		return (1);
	}
	else if (IS_K_SUPPR(buff))
	{
		if (ft_strlen(*line) > ((stock_data(NULL)->winsize).col - ft_strlen(stock_data(NULL)->prompt)) > 0)
		{
			
			tputs(tgetstr("ce", NULL), AFFCNT, &my_putchar);
			ft_putstr(*line + *pos);
			tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(*line + *pos)), AFFCNT, &my_putchar);
			return (1);
		}
		tputs(tgetstr("dc", NULL), AFFCNT, &my_putchar);
		delchar(line, *pos);
		if (history->ret && history->history_cur)
		{
			//*line = ((t_history_elem*)(((stock_data(NULL)->history).history_cur)->content))->value;
			((t_history_elem*)(history->history_cur->content))->flag_modif = 1;
		}
		return (1);
	}
	return (0);
}

static int is_ctrl_keys(char *buff, char **line, int *pos, char **strcpy)
{
	if (!buff || !line)
		return (0);
	if (IS_K_CTRL_I(buff))
		return (key_ctrl_y(line, pos, strcpy, &stock_data(NULL)->history));
	else if (IS_K_CTRL_U(buff))
		return (key_ctrl_u(line, pos, strcpy, &stock_data(NULL)->history));
	else if (IS_K_CTRL_K(buff))
		return (key_ctrl_k(line, pos, strcpy));
	else if (IS_K_CTRL_W(buff))
		return (1);
	return (0);
}

void	keyboard_handler(char *buff, t_editline *editline)
{
	if (((stock_data(NULL)->history).ret || IS_K_ARROW_UP(buff) ||
		((stock_data(NULL)->history).ret && IS_K_ARROW_DOWN(buff))) && (stock_data(NULL)->history).history_cur)
		editline->temp = &(((t_history_elem*)(((stock_data(NULL)->history).history_cur)->content))->value);
	else
		editline->temp = &editline->line;
	//printf("%d %d %d %d %d %d\n", buff[0], buff[1], buff[2], buff[3], buff[4], buff[5]);
	if (is_arrow_keys(buff, *editline->temp, &editline->pos, &stock_data(NULL)->history, editline))
		return ;
	else if (editline->temp && is_home_or_end_keys(buff, *editline->temp, &editline->pos))
		return ;
	else if (is_dels_keys(buff, editline->temp , &editline->pos, &stock_data(NULL)->history))
		return ;
	else if (is_ctrl_keys(buff,  editline->temp, &editline->pos, &editline->strcpy))
		return ;
	else if (is_alt_keys(buff, *editline->temp, &editline->pos))
		return ;
	else if (IS_K_RETURN(buff)) //ENTER
	{
		printf("\n%p:line:%s\tpos:%d\n", *editline->temp ,*editline->temp, editline->pos);
		key_return(editline->temp, &stock_data(NULL)->history);
		reset_line(&editline->line, &editline->pos);
		prompt(&stock_data(NULL)->prompt);
	}
	else if (ft_isprint(buff[0]))
		add_key(buff[0], &stock_data(NULL)->history, editline);
}
