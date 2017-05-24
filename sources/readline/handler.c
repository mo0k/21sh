/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:32 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 01:43:24 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

static int		ctrl_keys(int key, t_shell *sh)
{
	t_editline	*e;
	t_history 	*h;
	t_prompt 	*p;
	int r;

	e = &sh->editline;
	h = &sh->history;
	p = &sh->prompt;
	r = 0;
	(key == 11 && !r) ? kill_line(e, h) && (r = 1): 0;
	(key == 21 && !r) ? unix_line_discard(e, h) && (r = 1): 0;
	(key == 23 && !r) ? unix_word_rubout(e, h) && (r = 1): 0;
	(key == 25 && !r) ? paste(e, h) && (r = 1): 0;
	(key == 4 && !r) ? delete_char(e, h, p->len, sh->win.col) && (r = 1) : 0;
	(key == 8 && !r) ? backward_delete_char(e->temp, &e->pos, h) && (r = 1) : 0;
	(key == 1 && !r) ? beginning_of_line(&e->pos) && (r = 1) : 0;
	(key == 5 && !r) ? end_of_line(e, p->len, sh->win.col) && (r = 1) : 0;
	(key == 6 && !r) ? forward_char(e, p->len, sh->win.col) && (r = 1) : 0;
	(key == 2 && !r) ? backward_char(&e->pos) && (r = 1) : 0;
	(key == 12 && !r) ? do_clear(e, p->val, p->len, sh->win.col) && (r = 1) : 0;
	(key == 16 && !r) ? previous_history(sh) && (r = 1) : 0;
	(key == 14 && !r) ? next_history(sh) && (r = 1) : 0;
	(key == 18 && !r) ? search_history() && (r = 1) : 0;
	return (r);
}

static void		do_meta_key(t_editline *editline, t_history *history)
{
	int meta;
	int r;

	r = 0;
	meta = 0;
	if (read(0, &meta, sizeof(int)) > 0)
	{
		(meta == BACKWARD_WORD && !r) ? backward_word(*editline->temp, &editline->pos) && (r = 1): 0;
		(meta == CAPITALIZE_WORD && !r) ? capitalize_word(*editline->temp, &editline->pos) && (r = 1): 0;
		(meta == DOWNCASE_WORD && !r) ? downcase_word(*editline->temp, &editline->pos) && (r = 1): 0;
		(meta == FORWARD_WORD && !r) ? forward_word(*editline->temp, &editline->pos) && (r = 1): 0;
		(meta == KILL_WORD && !r) ? kill_word(editline, history) && (r = 1) : 0;
		(meta == UPCASE_WORD && !r) ? upcase_word(*editline->temp, &editline->pos) && (r = 1) : 0;
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
	(key == K_ARROW_RIGHT && !r) ? forward_char(editline, stock_data(NULL)->prompt.len, stock_data(NULL)->win.col) && (r = 1) : 0;
	(key == K_ARROW_LEFT && !r) ? backward_char(&editline->pos) && (r = 1) : 0;
	(key == K_ARROW_UP && !r) ? previous_history(stock_data(NULL)) && (r = 1) : 0;
	(key == K_ARROW_DOWN && !r) ? next_history(stock_data(NULL)) && (r = 1) : 0;
	(key == K_HOME && !r) ? beginning_of_line(&editline->pos) && (r = 1) : 0;
	(key == K_END && !r) ? end_of_line(editline, stock_data(NULL)->prompt.len, stock_data(NULL)->win.col) && (r = 1) : 0;
	(key == K_BACKSPACE && !r) ? delete_char(editline, history, stock_data(NULL)->prompt.len, stock_data(NULL)->win.col) && (r = 1) : 0;
	(key == K_DELETE && !r) ? backward_delete_char(editline->temp, &editline->pos, history) && (r = 1) : 0;
	//printf("r:%d\n", r);
	return (r);
}

void	readline_handler(int key, t_shell *shell)
{
	t_history *history;
	t_editline *editline;

	if (!shell)
		return ;
	history = &shell->history;
	editline = &shell->editline;
	//printf("%d\n", key);
	if ((history->ret || key == PREVIOUS_HISTORY ||
		(history->ret && key == NEXT_HISTORY)) && history->history_cur)
		editline->temp = &(((t_history_elem*)(history->history_cur->content))->value);
	else
		editline->temp = &editline->line;
	if (key == META_KEY)
		do_meta_key(editline, history);
	else if(ctrl_keys(key, shell))
		return ;
	else if(others_keys(key, editline, history))
		return ;
	else if (key == K_RETURN)
	{
		printf("\n%p:line:%s\tpos:%d\n", *editline->temp ,*editline->temp, editline->pos);
		k_return(editline->temp, history);
		reset_line(&editline->line, &editline->pos);
		prompt(stock_data(NULL)->prompt.val);
	}
	else if (ft_isprint(key))
		add_key(key, shell);
}
