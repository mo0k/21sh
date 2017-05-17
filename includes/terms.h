/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terms.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:30:52 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/17 04:58:44 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MANAGE_TERMIOS_H
# define MANAGE_TERMIOS_H

# define AFFCNT 1

# include <libft.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <error.h>

# define ERR_GETENV "Environnement TERM no define"
# define ERR_TGETENT_NOFOUND "The terminfo database could not be found"
# define ERR_TGETENT_NOENTRY "There is no such entry for TERM value"
# define ERR_TCGETATTR "Impossible to copy the parameters associated with the terminal referenced"
# define ERR_WINSIZE "Terminal width is too small"

typedef struct	termios t_termios;

typedef unsigned int t_uint;

typedef struct s_win
{
	t_uint		col;
	t_uint		row;
	t_uint		cursor_pos;
}				t_win;

typedef struct	s_term
{
	t_termios	*new;
	t_termios	*origin;
}				t_term;

#include <ft_21sh.h>

void		init_term(t_termios **new, t_termios **origin);
int			init_config_term(t_termios *new, t_termios *origin);
int			restore_config_term(void);
int			my_putchar(int c);
void		init_winsize(t_win *winsize, t_uint row, t_uint col);

#endif