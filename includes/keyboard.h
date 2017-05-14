/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/14 16:40:12 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_HANDLER
# define KEYBOARD_HANDLER

# define IS_K_SPEC(x) (x[0] == 27 && x[1] == 91) ? 1 : 0
# define IS_K_ARROW_RIGHT(x) ((IS_K_SPEC(x)) && x[2] == 67) ? 1 : 0
# define IS_K_ARROW_LEFT(x) ((IS_K_SPEC(x)) && x[2] == 68) ? 1 : 0
# define IS_K_ARROW_UP(x) ((IS_K_SPEC(x)) && x[2] == 65) ? 1 : 0
# define IS_K_ARROW_DOWN(x) ((IS_K_SPEC(x)) && x[2] == 66) ? 1 : 0
# define IS_K_HOME(x) ((IS_K_SPEC(x)) && x[2] == 72) ? 1 : 0
# define IS_K_END(x) ((IS_K_SPEC(x)) && x[2] == 70) ? 1 : 0
# define IS_K_SUPPR(x) ((IS_K_SPEC(x)) && x[2] == 51 && x[3] == 126) ? 1 : 0
# define IS_K_DELETE(x) (x[0] == 127 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_K_RETURN(x) (x[0] == 10 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_K_CTRL_Y(x) (x[0] == 10 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_K_CTRL_U(x) (x[0] == 21 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_K_CTRL_K(x) (x[0] == 11 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_K_CTRL_W(x) (x[0] == 23 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_K_ALT_UP(x) (x[0] == 27 && x[1] == 27 && x[2] == 91 && x[3] == 65) ? 1 : 0
# define IS_K_ALT_DOWN(x) (x[0] == 27 && x[1] == 27 && x[2] == 91 && x[3] == 66) ? 1 : 0
# define IS_K_ALT_RIGHT(x) (x[0] == 27 && x[1] == 27 && x[2] == 91 && x[3] == 67) ? 1 : 0
# define IS_K_ALT_LEFT(x) (x[0] == 27 && x[1] == 27 && x[2] == 91 && x[3] == 68) ? 1 : 0

# include <ft_21sh.h>

void	keyboard_handler(char *buff, t_editline *editline);
void	add_key(char c, t_history *history, t_editline *editline);
int 	key_arrow_right(int *pos, char *line);
int 	key_arrow_left(int *pos);
int 	key_arrow_home(int *pos);
int 	key_arrow_end(char *line, int *pos);
int 	key_delete(char **line, int *pos, t_history *history);
int 	key_suppr(char **line, int *pos, t_history *history);
int 	key_return(char **line, t_history *history);
int 	key_alt_up(int *pos, char *line);
int 	key_alt_down(int *pos, char *line);
int 	key_alt_right(int *pos, char *line);
int 	key_alt_left(int *pos, char *line);
int 	key_ctrl_y(char **line, int *pos, char **strcpy);
int 	key_ctrl_u(char **line, int *pos, char **strcpy);
int 	key_ctrl_k(char **line, int *pos, char **strcpy);
int 	key_ctrl_w(char **line, int *pos, char **strcpy);


#endif