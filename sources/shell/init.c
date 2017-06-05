/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:35:09 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/05 10:06:45 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_21sh.h>

void	init(t_shell *sh)
{
	init_config(&((sh->termios).new), &((sh->termios).origin));
	init_readline(&sh->readline);
	init_history(&sh->history);
	init_tokenizer(&sh->tokenizer);
	//faire fct init prompt dans class prompt
	//stock->prompt.val = getcwd(NULL, CWD);
	//stock->prompt.len  = ft_strlen(stock->prompt.val) + LEN_SYMBOL;

}
