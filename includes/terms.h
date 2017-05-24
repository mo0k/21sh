/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terms.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:30:52 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/24 16:38:17 by mo0ky            ###   ########.fr       */
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
# include <ft_21sh.h>

# define ERR_GETENV "Environnement TERM no define"
# define ERR_TGETENT_NOFOUND "The terminfo database could not be found"
# define ERR_TGETENT_NOENTRY "There is no such entry for TERM value"
# define ERR_TCGETATTR "Impossible to copy the parameters associated with the terminal referenced"
# define ERR_WINSIZE "Terminal width is too small"

void		init_config(t_termios **new, t_termios **origin);
void		ft_cfmakeraw(t_termios *conf);
int			restore_config(t_termios *origin);
int			my_putchar(int c);

#endif