/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:30:40 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/18 23:45:30 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <terms.h>

int			my_putchar(int c)
{
	write(isatty(STDOUT_FILENO), &c, 1);
	return (1);
}

void		init_term(t_termios **new, t_termios **origin)
{
	if (!(*new = (t_termios*)malloc(sizeof(t_termios))))
		exit(EXIT_FAILURE);
	if (!(*origin = (t_termios*)malloc(sizeof(t_termios))))
		exit(EXIT_FAILURE);
	init_config_term(*new, *origin);
}

static void	ft_cfmakeraw(t_termios *conf)
{
	conf->c_iflag &= ~(IMAXBEL | IGNBRK | BRKINT | PARMRK | ISTRIP |
			INLCR | IGNCR | ICRNL | IXON);
	conf->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	conf->c_cflag &= ~(CSIZE | PARENB);
	conf->c_cflag |= CS8;
	conf->c_cc[VMIN] = 1;
	conf->c_cc[VTIME] = 0;
}

int			init_config_term(t_termios *new, t_termios *origin)
{
	char	*name;
	int 	ret;

	(!getenv("TERM")) ? ft_fatal(ERR_GETENV) : (name = getenv("TERM"));
	if ((ret = tgetent(NULL, name)) == -1)
		ft_fatal(ERR_TGETENT_NOFOUND);
	else if (ret == 0)
		ft_fatal(ERR_TGETENT_NOENTRY);
	if (tcgetattr(0, new) == -1)
		ft_fatal(ERR_TCGETATTR);
	if (!(origin = (t_termios*)ft_memmove((t_termios*)origin, (t_termios*)new, sizeof(t_termios))))
		exit(EXIT_FAILURE);
	//new->c_lflag &= ~(ICANON | ECHO);
	//new->c_cc[VMIN] = 1;
	//new->c_cc[VTIME] = 0;
	ft_cfmakeraw(new);
	if (tcsetattr(0, TCSADRAIN, new) == -1)
		exit(EXIT_FAILURE);
	tgetflag("km");
	return (1);
}

int			restore_config_term(void)
{
	if (tcsetattr(0, TCSADRAIN, (stock_data(NULL)->termios).origin) == -1)
		exit(EXIT_FAILURE);
	return (1);
}

void		init_winsize(t_win *winsize, t_uint row, t_uint col)
{
	winsize->col = col;
	winsize->row = row;
}