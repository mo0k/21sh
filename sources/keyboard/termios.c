/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:30:40 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/06 23:44:32 by mo0ky            ###   ########.fr       */
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
	new->c_lflag &= ~(ICANON | ECHO);
	new->c_cc[VMIN] = 1;
	new->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, new) == -1)
		exit(EXIT_FAILURE);
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