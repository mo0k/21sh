/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:14:11 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/24 15:51:50 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_21sh.h>

int			prompt(char *str)
{
	//char	*currentdir;

	//currentdir = getcwd(NULL, CWD);
	if (str)
	{
		ft_putstrcolor(str, PROMPT_COLOR);
		ft_putstrcolor(SYMBOL, SYMBOL_COLOR);
	}
	else
	{
		//str = ft_strdup(PROMPT);
		ft_putstr(C_PROMPT);
	}
	//free(currentdir);
	return (1);
}
