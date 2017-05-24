/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:08:57 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 01:42:24 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include <keys.h>
# include <ft_21sh.h>

void	init_line(t_editline *editline);
void	reset_line(char **line, int *pos);
void	padding_limit(int pos, int len_prompt, int col);

void	readline_handler(int key, t_shell *shell);
void	add_key(char c, t_shell *sh);
int 	backward_char(int *pos);
int		backward_delete_char(char **line, int *pos, t_history *history);
int 	backward_word(char *line, int *pos);
int 	beginning_of_line(int *pos);
int		capitalize_word(char *line, int *pos);
int		delete_char(t_editline *editline, t_history *history, int len_prompt, int col);
int		downcase_word(char *line, int *pos);
int		do_clear(t_editline *e, char *prompt_val, int prompt_len, int col);
int 	end_of_line(t_editline *editline, int prompt_len, int col);
int 	forward_char(t_editline *editline, int prompt_len, int col);
int 	forward_word(char *line, int *pos);
int 	kill_line(t_editline *editline, t_history *history);
int		kill_word(t_editline *editline, t_history *history);
int 	line_down(char *line, int *pos);
int 	line_up(char *line, int *pos);
int 	next_history(t_shell *shell);
int 	paste(t_editline *editline, t_history *history);
int 	previous_history(t_shell *shell);
int		search_history(void);
int 	unix_line_discard(t_editline *editline, t_history *history);
int 	unix_word_rubout(t_editline *editline, t_history *history);
int		upcase_word(char *line, int *pos);
int		k_delete(char **line, int *pos, t_history *history);
int 	k_return(char **line, t_history *history);


#endif