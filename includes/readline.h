/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:08:57 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/20 13:14:17 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include <keys.h>

enum e_cut
{
	key_u = 1,
	key_k,
	key_w
};

typedef struct	s_editline
{
	char		*line;
	char		**temp;
	char		*strcpy;
	int 		pos;
	enum e_cut	cut;
}				t_editline;

# include <history.h>
# include <ft_21sh.h>

void	init_line(t_editline *editline);
void	reset_line(char **line, int *pos);

void	readline_handler(int key, t_editline *editline, t_history *history);
void	add_key(char c, t_history *history, t_editline *editline);
int 	backward_char(int *pos);
int		backward_delete_char(char **line, int *pos, t_history *history);
int 	backward_word(char *line, int *pos);
int 	beginning_of_line(int *pos);
int		capitalize_word(void);
int		delete_char(t_editline *editline, t_history *history, int len_prompt);
int		downcase_word(void);
int		do_clear_screen(void);
int 	end_of_line(char *line, int *pos);
int 	forward_char(char *line, int *pos);
int 	forward_word(char *line, int *pos);
int 	kill_line(t_editline *editline, t_history *history);
int		kill_word(void);
int 	line_down(char *line, int *pos);
int 	line_up(char *line, int *pos);
int 	next_history(t_editline *editline, t_history *h);
int 	paste(t_editline *editline, t_history *history);
int 	previous_history(t_editline *editline, t_history *h);
int		search_history(void);
int 	unix_line_discard(t_editline *editline, t_history *history);
int 	unix_word_rubout(t_editline *editline, t_history *history);
int		upcase_word(void);
int		k_delete(char **line, int *pos, t_history *history);
int 	k_return(char **line, t_history *history);


#endif