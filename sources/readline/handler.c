/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:32 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/20 16:01:08 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

static int		ctrl_keys(int key, t_editline *editline, t_history *history)
{
	int r;

	r = 0;
	(key == 11 && !r) ? kill_line(editline, history) && (r = 1): 0;
	(key == 21 && !r) ? unix_line_discard(editline, history) && (r = 1): 0;
	(key == 23 && !r) ? unix_word_rubout(editline, history) && (r = 1): 0;
	(key == 25 && !r) ? paste(editline, history) && (r = 1): 0;
	(key == 4 && !r) ? delete_char(editline, history, ft_strlen(stock_data(NULL)->prompt) + 3) && (r = 1) : 0;
	(key == 8 && !r) ? backward_delete_char(editline->temp, &editline->pos, history) && (r = 1) : 0;
	(key == 1 && !r) ? beginning_of_line(&editline->pos) && (r = 1) : 0;
	(key == 5 && !r) ? end_of_line(*editline->temp, &editline->pos) && (r = 1) : 0;
	(key == 6 && !r) ? forward_char(*editline->temp, &editline->pos) && (r = 1) : 0;
	(key == 2 && !r) ? backward_char(&editline->pos) && (r = 1) : 0;
	(key == 12 && !r) ? do_clear_screen() && (r = 1) : 0;
	(key == 16 && !r) ? previous_history(editline, history) && (r = 1) : 0;
	(key == 14 && !r) ? next_history(editline, history) && (r = 1) : 0;
	(key == 18 && !r) ? search_history() && (r = 1) : 0;
	//printf("ret:%d\n", ret);
	return (r);
}

static void		do_meta_key(t_editline *editline, t_history *history)
{
	(void)history;
	int meta;
	int r;

	r = 0;
	meta = 0;
	if (read(0, &meta, sizeof(int)) > 0)
	{
		(meta == BACKWARD_WORD && !r) ? backward_word(*editline->temp, &editline->pos) && (r = 1): 0;
		(meta == CAPITALIZE_WORD && !r) ? capitalize_word() && (r = 1): 0;
		(meta == DOWNCASE_WORD && !r) ? downcase_word() && (r = 1): 0;
		(meta == FORWARD_WORD && !r) ? forward_word(*editline->temp, &editline->pos) && (r = 1): 0;
		(meta == KILL_WORD && !r) ? kill_word() && (r = 1) : 0;
		(meta == UPCASE_WORD && !r) ? upcase_word() && (r = 1) : 0;
	}
}

static int		others_keys(int key, t_editline *editline, t_history *history)
{
	(void)key;
	(void)editline;
	(void)history;
	int r;

	r = 0;
	(key == LINE_UP && !r) ? line_up(*editline->temp, &editline->pos) && (r = 1): 0;
	(key == LINE_DOWN && !r) ? line_down(*editline->temp, &editline->pos) && (r = 1): 0;
	(key == K_ALT_RIGHT && !r) ? forward_word(*editline->temp, &editline->pos) && (r = 1): 0;
	(key == K_ALT_RIGHT && !r)	? backward_word(*editline->temp, &editline->pos) && (r = 1): 0;
	(key == K_ARROW_RIGHT && !r) ? forward_char(*editline->temp, &editline->pos) && (r = 1) : 0;
	(key == K_ARROW_LEFT && !r) ? backward_char(&editline->pos) && (r = 1) : 0;
	(key == K_ARROW_UP && !r) ? previous_history(editline, history) && (r = 1) : 0;
	(key == K_ARROW_DOWN && !r) ? next_history(editline, history) && (r = 1) : 0;
	(key == K_HOME && !r) ? beginning_of_line(&editline->pos) && (r = 1) : 0;
	(key == K_END && !r) ? end_of_line(*editline->temp, &editline->pos) && (r = 1) : 0;
	(key == K_BACKSPACE && !r) ? delete_char(editline, history, ft_strlen(stock_data(NULL)->prompt) + 3) && (r = 1) : 0;
	(key == K_DELETE && !r) ? backward_delete_char(editline->temp, &editline->pos, history) && (r = 1) : 0;
	//printf("r:%d\n", r);
	return (r);
}

void	readline_handler(int key, t_editline *editline, t_history *history)
{
	//printf("%d\n", key);
	if ((history->ret || key == PREVIOUS_HISTORY ||
		(history->ret && key == NEXT_HISTORY)) && history->history_cur)
		editline->temp = &(((t_history_elem*)(history->history_cur->content))->value);
	else
		editline->temp = &editline->line;

	if (key == META_KEY)
		do_meta_key(editline, history);
	else if(ctrl_keys(key, editline, history))
		return ;
	else if(others_keys(key, editline, history))
		return ;
	else if (key == K_RETURN)
	{
		printf("\n%p:line:%s\tpos:%d\n", *editline->temp ,*editline->temp, editline->pos);
		k_return(editline->temp, history);
		reset_line(&editline->line, &editline->pos);
		prompt(stock_data(NULL)->prompt);
	}
	else if (ft_isprint(key))
		add_key(key, history, editline);
}
/*
void	keyboard_handler(char *buff, t_editline *editline)
{
	if (((stock_data(NULL)->history).ret || K_ARROW_UP(buff) ||
		((stock_data(NULL)->history).ret && K_ARROW_DOWN(buff))) && (stock_data(NULL)->history).history_cur)
		editline->temp = &(((t_history_elem*)(((stock_data(NULL)->history).history_cur)->content))->value);
	else
		editline->temp = &editline->line;
	printf("%d %d %d %d\n", buff[0], buff[1], buff[2], buff[3]);
	//printf("%d\n", (int)buff);

	if (is_arrow_keys(buff, editline, &stock_data(NULL)->history))
		return ;
	else if (editline->temp && is_home_or_end_keys(buff, *editline->temp, &editline->pos))
		return ;
	else if (is_dels_keys(buff, editline->temp , &editline->pos, &stock_data(NULL)->history))
		return ;
	else if (is_ctrl_keys(buff,  editline, &stock_data(NULL)->history))
		return ;
	else if (is_alt_keys(buff, *editline->temp, &editline->pos))
		return ;
	else if (buff[0] == 3 &&  buff[1] == 0 && buff[2] == 0)
	{
		printf("dwadwadwadwa\n");
		signal(SIGINT, SIG_DFL);
	}
	else if (buff[0] == 27 &&  buff[1] == 0 && buff[2] == 0)
	{

		printf("KKKKKKKKKKK\n");
		//tputs(tgetstr("mm", NULL), AFFCNT, &my_putchar);
		char buff_meta[4];
		ft_memset(buff, 0, 4);
		read(STDIN_FILENO, &buff_meta, 4);
		printf("buff:%d\n", *buff_meta);
		if (*buff_meta == 100)
			printf("KILL-WORD\n");
		//§tputs(tgetstr("mo", NULL), AFFCNT, &my_putchar);
	}
	else if (K_RETURN(buff)) //ENTER
	{
		printf("\n%p:line:%s\tpos:%d\n", *editline->temp ,*editline->temp, editline->pos);
		k_return(editline->temp, &stock_data(NULL)->history);
		reset_line(&editline->line, &editline->pos);
		prompt(&stock_data(NULL)->prompt);
	}
	else if (ft_isprint(buff[0]))
		add_key(buff[0], &stock_data(NULL)->history, editline);
}
*/
//