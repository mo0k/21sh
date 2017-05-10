/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:00:48 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/06 23:38:41 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals.h>

void		catch_signals(void)
{
	int sig;

	sig = 0;
	while (++sig < 32)
	{
		if (sig == SIGWINCH || sig == SIGTSTP || sig == SIGCONT)
			signal(sig, &handler_signals);
		//else
		//	signal(sig, SIG_IGN);
	}
}