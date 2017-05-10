/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:32 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/07 23:15:31 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

static 	int is_arrow_keys(char *buff, char *line, int *pos, t_history *history,  t_editline *editline)
{
	if (!buff)
		return (0);
	if (*pos > 0 && IS_KEY_ARROW_LEFT(buff))
		return (key_arrow_left(pos));
	else if (*pos < (int)ft_strlen(line) && IS_KEY_ARROW_RIGHT(buff))
		return (key_arrow_right(pos));
	else if (IS_KEY_ARROW_UP(buff))
		return ((history->ret = move_history(&history->history_cur, &history->in, up, editline)));
	else if (IS_KEY_ARROW_DOWN(buff))
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
	if (*pos > 0 && IS_KEY_HOME(buff))
		return (key_arrow_home(pos));
	else if (*pos < (int)ft_strlen(line) && IS_KEY_END(buff))
		return (key_arrow_end(line, pos));
	return (0);
}

static int 	is_dels_keys(char *buff, char **line, int *pos, t_history *history)
{
	if (!buff || !line || !*line || !history)
		return (0);
	if (*pos > 0 && IS_KEY_DELETE(buff))
	{
		tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
		tputs(tgetstr("dc", NULL), AFFCNT, &my_putchar);
		(*pos)--;
		delchar(line, *pos);
		if (history->ret && history->history_cur)
		{
			//*line = ((t_history_elem*)(((stock_data(NULL)->history).history_cur)->content))->value;
			((t_history_elem*)(history->history_cur->content))->flag_modif = 1;
		}
		return (1);
	}
	else if (IS_KEY_SUPPR(buff))
	{
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

void	keyboard_handler(char *buff, t_editline *editline)
{
	//if ((stock_data(NULL)->history).history_cur)
	//	printf("HISTORY OK\n");
	//else
	//	printf("HISTORY NO\n");
	if (((stock_data(NULL)->history).ret || IS_KEY_ARROW_UP(buff) ||
		((stock_data(NULL)->history).ret && IS_KEY_ARROW_DOWN(buff))) && (stock_data(NULL)->history).history_cur)
		editline->temp = &(((t_history_elem*)(((stock_data(NULL)->history).history_cur)->content))->value);
	else
		editline->temp = &editline->line;
	//printf("\naddress editline->temp:%p\t%p\n", editline->temp, *editline->temp);
	//printf("address editline->line:%p\t%p\n", &editline->line, editline->line);
	//printf("address hisrtory->line:%p\t%p\n", &(((t_history_elem*)(((stock_data(NULL)->history).history_cur)->content))->value),((t_history_elem*)(((stock_data(NULL)->history).history_cur)->content))->value);
	//printf("%d %d %d %d %d %d\n", buff[0], buff[1], buff[2], buff[3], buff[4], buff[5]);
	if (is_arrow_keys(buff, *editline->temp, &editline->pos, &stock_data(NULL)->history, editline))
		return ;
	else if (editline->temp && is_home_or_end_keys(buff, *editline->temp, &editline->pos))
		return ;
	else if (is_dels_keys(buff, editline->temp , &editline->pos, &stock_data(NULL)->history))
		return ;
	else if (IS_KEY_SHIFT(buff))
	{
		tputs(tgetstr("mr", NULL), AFFCNT, &my_putchar);
		if (buff[3] == 59 && buff[4] == 50 && buff[5] == 67)
		{
			tputs(tgetstr("nd", NULL), AFFCNT, &my_putchar);
			//printf("SHIFT + RIGHT\n");
		}
		else if (buff[3] == 59 && buff[4] == 50 && buff[5] == 68)
		{
			tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
			//printf("SHIFT + LEFT\n");
		}
		tputs(tgetstr("me", NULL), AFFCNT, &my_putchar);
	}
	else if (IS_KEY_RETURN(buff)) //ENTER
	{
		printf("\n%p:line:%s\tpos:%d\n", *editline->temp ,*editline->temp, editline->pos);
		key_return(editline->temp, &stock_data(NULL)->history);
		reset_line(&editline->line, &editline->pos);
		prompt();
	}
	else if (ft_isprint(buff[0]))
		add_key(buff[0], &stock_data(NULL)->history, editline);
}
