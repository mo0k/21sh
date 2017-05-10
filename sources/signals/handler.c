/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:00:48 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/06 23:38:47 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals.h>

static void			winsize_changed(void)
{
	t_shell			*tmp;
	struct winsize	ws;

	tmp = stock_data(NULL);
	ioctl(isatty(STDOUT_FILENO), TIOCGWINSZ, &ws);
	init_winsize(&(tmp->winsize), ws.ws_row, ws.ws_col);
}

void				handler_signals(int sig)
{
	//tputs(tgetstr("cl", NULL), 1, &my_putchar);
	if (sig == SIGWINCH)
		winsize_changed();
	else if (sig == SIGTSTP )
	{
		restore_config_term();
		signal(SIGTSTP, SIG_DFL);
		ioctl(isatty(STDOUT_FILENO), TIOCSTI, "\032");
	}
	else if (sig == SIGCONT)
	{
		catch_signals();
		init_config_term((stock_data(NULL)->termios).new, (stock_data(NULL)->termios).origin);
		winsize_changed();
	}
	else
	{
		restore_config_term();
		exit(1);
	}
}