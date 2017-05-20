/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:35:09 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/19 23:24:40 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_21sh.h>

void	init(t_shell *stock)
{
	init_config(&((stock->termios).new), &((stock->termios).origin));
	init_line(&stock->editline);
	init_winsize(&(stock->winsize), tgetnum("li"), tgetnum("co"));
	init_history(&stock->history);
	stock->prompt = getcwd(NULL, CWD);
}
