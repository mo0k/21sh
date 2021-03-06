/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:08:57 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/19 15:56:04 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include <keys.h>
# include <ft_21sh.h>

typedef enum	e_protect
{
	quote = -1,
	quotes = -2,
	backslack = -3
}				t_protect;

void	init_readline(t_readline *readline);
void	reset_line(char **line, int *pos);
//void	print_line(char *line, int in_newline);
void	padding_limit(int pos, int len_prompt, int col);

int		readline_handler(int key, t_readline *readline, t_history *h);//, int *in_newline);
int		add_key(char c, t_readline *readline, t_history *history);
void	quoting(char **line);
int		check_protection(char *str);
int 	backward_char(int *pos);
int		backward_delete_char(t_readline *readline, t_history *history);
int 	backward_word(t_readline *readline);
int 	beginning_of_line(int *pos);
int		capitalize_word(t_readline *readline, t_history *history);
int		delete_char(t_readline *readline, t_history *history);
int		downcase_word(t_readline *readline, t_history *history);
int		do_clear(t_readline *e);
int 	end_of_line(t_readline *readline);
int 	forward_char(t_readline *readline);
int 	forward_word(t_readline *readline);
int 	kill_line(t_readline *readline, t_history *history);
int		kill_word(t_readline *readline, t_history *history);
int 	line_down(t_readline *readline);
int 	line_up(t_readline *readline);
int 	next_history(t_readline *readline, t_history *history);
int 	paste(t_readline *readline, t_history *history);
int 	previous_history(t_readline *readline, t_history *history);
int		search_history(void);
int 	unix_line_discard(t_readline *readline, t_history *history);
int 	unix_word_rubout(t_readline *readline, t_history *history);
int		upcase_word(t_readline *readline, t_history *history);
int 	k_return(char **line, t_history *history);//, int *in_newline);


#endif