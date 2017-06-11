/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:32 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/09 23:59:29 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

static int		ctrl_keys(int key, t_readline *e, t_history *h)
{
	int x;

	x = 0;
	(key == KILL_LINE && !x) ? kill_line(e, h) && (x = 1) : 0;
	(key == UNIX_LINE_DISCARD && !x) ? unix_line_discard(e, h) && (x = 1) : 0;
	(key == UNIX_WORD_RUBOUT && !x) ? unix_word_rubout(e, h) && (x = 1) : 0;
	(key == PASTE && !x) ? paste(e, h) && (x = 1) : 0;
	(key == DELETE_CHAR && !x) ? delete_char(e, h) && (x = 1) : 0;
	(key == BACK_DELETE_CHAR && !x) ? backward_delete_char(e, h) && (x = 1) : 0;
	(key == BEGIN_OF_LINE && !x) ? beginning_of_line(&e->pos) && (x = 1) : 0;
	(key == END_OF_LINE && !x) ? end_of_line(e) && (x = 1) : 0;
	(key == FORWARD_CHAR && !x) ? forward_char(e) && (x = 1) : 0;
	(key == BACKWARD_CHAR && !x) ? backward_char(&e->pos) && (x = 1) : 0;
	(key == CLEAR_SCREEN && !x) ? do_clear(e) && (x = 1) : 0;
	(key == PREVIOUS_HISTORY && !x) ? previous_history(e, h) && (x = 1) : 0;
	(key == NEXT_HISTORY && !x) ? next_history(e, h) && (x = 1) : 0;
	(key == SEARCH_HISTORY && !x) ? search_history() && (x = 1) : 0;
	return (x);
}

static int		do_meta_key(t_readline *r, t_history *h)
{
	int meta;
	int x;

	x = 0;
	meta = 0;
	//printf("PAR LA COCO\n");
	if (read(0, &meta, sizeof(int)) > 0)
	{
		(meta == BACKWARD_WORD && !x) ? backward_word(r) && (x = 1) : 0;
		(meta == CAPITALIZE_WORD && !x) ? capitalize_word(r, h) && (x = 1) : 0;
		(meta == DOWNCASE_WORD && !x) ? downcase_word(r, h) && (x = 1) : 0;
		(meta == FORWARD_WORD && !x) ? forward_word(r) && (x = 1) : 0;
		(meta == KILL_WORD && !x) ? kill_word(r, h) && (x = 1) : 0;
		(meta == UPCASE_WORD && !x) ? upcase_word(r, h) && (x = 1) : 0;
	}
	//printf("x:%d\n", x);
	return ((x) ? 1 : 0);
}

static int		others_keys(int key, t_readline *r, t_history *h)
{
	int x;

	x = 0;
	(key == LINE_UP && !x) ? line_up(r) && (x = 1) : 0;
	(key == LINE_DOWN && !x) ? line_down(r) && (x = 1) : 0;
	(key == K_ALT_RIGHT && !x) ? forward_word(r) && (x = 1) : 0;
	(key == K_ALT_RIGHT && !x) ? backward_word(r) && (x = 1) : 0;
	(key == K_ARROW_RIGHT && !x) ? forward_char(r) && (x = 1) : 0;
	(key == K_ARROW_LEFT && !x) ? backward_char(&r->pos) && (x = 1) : 0;
	(key == K_ARROW_UP && !x) ? previous_history(r, h) && (x = 1) : 0;
	(key == K_ARROW_DOWN && !x) ? next_history(r, h) && (x = 1) : 0;
	(key == K_HOME && !x) ? beginning_of_line(&r->pos) && (x = 1) : 0;
	(key == K_END && !x) ? end_of_line(r) && (x = 1) : 0;
	(key == K_BACKSPACE && !x) ? delete_char(r, h) && (x = 1) : 0;
	(key == K_DELETE && !x) ? backward_delete_char(r, h) && (x = 1) : 0;
	//printf("r:%d\n", r);
	return (x);
}

int	readline_handler(int key, t_readline *readline, t_history *h, int *new_line)
{
		//printf("DEBUG | START readline_handler:%d\n", *new_line);
	if (!readline)
		return (0);
	if (h && h->history_cur && (h->ret || key == PREVIOUS_HISTORY ||
		(h->ret && key == NEXT_HISTORY)))
		readline->temp = &(((t_history_elem*)(h->history_cur->content))->value);
	else
		readline->temp = &readline->line;
	//printf("DEBUG | &readline->line:\t%p, readline->line:%p\n", &readline->line, readline->line);
	//printf("DEBUG | readline->temp:\t%p\n", *readline->temp);
	//printf("key:%d\n", key);
	if (key == META_KEY && do_meta_key(readline, h))
		return (1);
	else if(ctrl_keys(key, readline, h))
		return (1);
	else if(others_keys(key, readline, h))
		return (1);
	else if (key == K_RETURN)
	{
		//printf("DEBUG | K_RETURN\n");
		//printf("DEBUG | *newline:%d\n", *new_line);
		if (!*new_line)
		{
			//printf("DEBUG | !newline:%d\n", *new_line);
			//printf("\n%p:line:%s\tpos:%d\n", *readline->temp ,*readline->temp, readline->pos);
			int ret = k_return(readline->temp, h, new_line);
			reset_line(&readline->line, &readline->pos);
			//prompt(readline->prompt.val);
			return (ret);
		}
		else
		{
			printf("DEBUG | return end handler newline\n");
			return (2);
		}
	}
	else if (ft_isprint(key) && add_key(key, readline, h))
		return (1);
	return (0);
}
