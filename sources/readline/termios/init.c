/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:30:40 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/31 18:43:09 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <terms.h>

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
	ft_cfmakeraw(new);
	if (tcsetattr(0, TCSADRAIN, new) == -1)
		exit(EXIT_FAILURE);
	return (1);
}

void		init_config(t_termios **new, t_termios **origin)
{
	if (!(*new = (t_termios*)malloc(sizeof(t_termios))))
		exit(EXIT_FAILURE);
	if (!(*origin = (t_termios*)malloc(sizeof(t_termios))))
		exit(EXIT_FAILURE);
	init_config_term(*new, *origin);
}
