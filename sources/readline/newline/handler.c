/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:32 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/08 14:14:57 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <newline.h>

static int		ctrl_keys(int key, t_readline *e)
{
	int x;

	x = 0;
	(key == KILL_LINE && !x) ? kill_line(e, 0) && (x = 1): 0;
	(key == UNIX_LINE_DISCARD && !x) ? unix_line_discard(e, 0) && (x = 1): 0;
	(key == UNIX_WORD_RUBOUT && !x) ? unix_word_rubout(e, 0) && (x = 1): 0;
	(key == PASTE && !x) ? paste(e, 0) && (x = 1): 0;
	(key == DELETE_CHAR && !x) ? delete_char(e, 0) && (x = 1) : 0;
	(key == BACK_DELETE_CHAR && !x) ? backward_delete_char(e, 0) && (x = 1) : 0;
	(key == BEGIN_OF_LINE && !x) ? beginning_of_line(&e->pos) && (x = 1) : 0;
	(key == END_OF_LINE && !x) ? end_of_line(e) && (x = 1) : 0;
	(key == FORWARD_CHAR && !x) ? forward_char(e) && (x = 1) : 0;
	(key == BACKWARD_CHAR && !x) ? backward_char(&e->pos) && (x = 1) : 0;
	return (x);
}

static int		do_meta_key(t_readline *r)
{
	int meta;
	int x;

	x = 0;
	meta = 0;
	if (read(0, &meta, sizeof(int)) > 0)
	{
		(meta == BACKWARD_WORD && !x) ? backward_word(r) && (x = 1): 0;
		(meta == CAPITALIZE_WORD && !x) ? capitalize_word(r, 0) && (x = 1): 0;
		(meta == DOWNCASE_WORD && !x) ? downcase_word(r, 0) && (x = 1): 0;
		(meta == FORWARD_WORD && !x) ? forward_word(r) && (x = 1): 0;
		(meta == KILL_WORD && !x) ? kill_word(r, 0) && (x = 1) : 0;
		(meta == UPCASE_WORD && !x) ? upcase_word(r, 0) && (x = 1) : 0;
	}
	return ((x) ? 1 : 0);
}

static int		others_keys(int key, t_readline *r)
{
	int x;

	x = 0;
	(key == LINE_UP && !x) ? line_up(r) && (x = 1): 0;
	(key == LINE_DOWN && !x) ? line_down(r) && (x = 1): 0;
	(key == K_ALT_RIGHT && !x) ? forward_word(r) && (x = 1): 0;
	(key == K_ALT_RIGHT && !x)	? backward_word(r) && (x = 1): 0;
	(key == K_ARROW_RIGHT && !x) ? forward_char(r) && (x = 1) : 0;
	(key == K_ARROW_LEFT && !x) ? backward_char(&r->pos) && (x = 1) : 0;
	(key == K_HOME && !x) ? beginning_of_line(&r->pos) && (x = 1) : 0;
	(key == K_END && !x) ? end_of_line(r) && (x = 1) : 0;
	(key == K_BACKSPACE && !x) ? delete_char(r, 0) && (x = 1) : 0;
	(key == K_DELETE && !x) ? backward_delete_char(r, 0) && (x = 1) : 0;
	return (x);
}

int				newline_handler(int key, t_readline *readline)
{
	//printf("start newline_readline_handler\n");
	if (!readline)
		return (0);
	if (key == META_KEY && do_meta_key(readline))
		return (1);
	else if(ctrl_keys(key, readline))
		return (1);
	else if(others_keys(key, readline))
		return (1);
	else if (key == K_RETURN)
	{
		// A MODIF POUR QUOTING
		//if (!*readline->temp)
			//ft_addchar(readline->temp, '\n');
		printf("NEWLINE ::::: %p:line:%s\tpos:%d\n", *readline->temp ,*readline->temp, readline->pos);
		//k_return(readline->temp, h);
		//reset_line(&readline->line, &readline->pos);
		//prompt(readline->prompt.val);
		return (2);
	}
	else if (ft_isprint(key) && add_key(key, readline, 0))
		return (1);
	return (0);
}
