/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_21sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:07:38 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/20 11:26:59 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_21SH_H
# define FT_21SH_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <libft.h>
# include <get_next_line.h>
# include <error.h>
# include <signals.h>
# include <history.h>
# include <readline.h>
# include <terms.h>
//# include <keyboard.h>

typedef unsigned int t_uint;

typedef struct s_win
{
	t_uint		col;
	t_uint		row;
}				t_win;

typedef struct	s_shell
{
	t_editline	editline;
	t_term		termios;
	t_win		winsize;
	t_history	history;
	char		*prompt;
}				t_shell;

# define CWD 255
# define PROMPT "21sh_>"
# define PROMPT_COLOR C_GREEN
# define SYMBOL_COLOR C_CYAN
# define C_PROMPT PROMPT_COLOR PROMPT"_$> "C_DFL

void		usage(int ac, char **av);
void		init(t_shell *stock);
t_shell		*stock_data(t_shell *elem);
void		print_stock(t_shell *stock);

int			prompt(char *ptr);
void		init_winsize(t_win *winsize, t_uint row, t_uint col);
int			ft_delchar(char **str, int pos);

#endif