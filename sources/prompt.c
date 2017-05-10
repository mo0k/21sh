/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:14:11 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/07 15:00:48 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_21sh.h>

int			prompt(void)
{
	char	*currentdir;

	currentdir = getcwd(NULL, CWD);
	if (currentdir)
	{
		ft_putstrcolor(currentdir, PROMPT_COLOR);
		ft_putstrcolor(" > ", SYMBOL_COLOR);
	}
	else
		ft_putstr(C_PROMPT);
	free(currentdir);
	return (1);
}
