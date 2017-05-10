/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/07 22:29:44 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_HANDLER
# define KEYBOARD_HANDLER

# define IS_SPECIAL_KEYS(x) (x[0] == 27 && x[1] == 91) ? 1 : 0
# define IS_KEY_ARROW_RIGHT(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 67) ? 1 : 0
# define IS_KEY_ARROW_LEFT(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 68) ? 1 : 0
# define IS_KEY_ARROW_UP(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 65) ? 1 : 0
# define IS_KEY_ARROW_DOWN(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 66) ? 1 : 0
# define IS_KEY_HOME(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 72) ? 1 : 0
# define IS_KEY_END(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 70) ? 1 : 0
# define IS_KEY_SUPPR(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 51 && x[3] == 126) ? 1 : 0
# define IS_KEY_DELETE(x) (x[0] == 127 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_KEY_RETURN(x) (x[0] == 10 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_KEY_SHIFT(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 49) ? 1 : 0

# include <ft_21sh.h>

void	keyboard_handler(char *buff, t_editline *editline);
void	add_key(char c, t_history *history, t_editline *editline);
int 	key_arrow_right(int *pos);
int 	key_arrow_left(int *pos);
int 	key_arrow_home(int *pos);
int 	key_arrow_end(char *line, int *pos);
int 	key_delete(char **line, int *pos, t_history *history);
int 	key_suppr(char **line, int *pos, t_history *history);
int 	key_return(char **line, t_history *history);

#endif