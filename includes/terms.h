/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_termios.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:30:52 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/05 01:24:57 by mo0ky            ###   ########.fr       */
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

typedef struct	termios t_termios;

typedef unsigned int t_uint;

typedef struct s_win
{
	t_uint		col;
	t_uint		row;
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