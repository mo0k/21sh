/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:35:09 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/24 17:16:09 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_21sh.h>

void	init(t_shell *stock)
{
	init_config(&((stock->termios).new), &((stock->termios).origin));
	init_line(&stock->editline);
	init_winsize(&(stock->win), tgetnum("li"), tgetnum("co"));
	init_history(&stock->history);
	//faire fct init prompt dans class prompt
	stock->prompt.val = getcwd(NULL, CWD);
	stock->prompt.len  = ft_strlen(stock->prompt.val) + LEN_SYMBOL;

}
