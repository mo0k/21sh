/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triple_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:50:12 by jmoucade          #+#    #+#             */
/*   Updated: 2017/02/22 01:41:35 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			***ft_get_triple_tab(int line, int columm, int len)
{
	char		***tab;
	int			cells;
	int			cols;

	if (!line || !columm || !len)
		return (NULL);
	cells = 0;
	if (!(tab = (char***)malloc(sizeof(char**) * (line + 1))))
		return (NULL);
	while (cells < line)
	{
		if (!(tab[cells] = (char**)malloc(sizeof(char*) * (columm + 1))))
			return (NULL);
		cols = 0;
		while (cols < columm)
		{
			if (!(tab[cells][cols] = (char*)malloc(sizeof(char) * (len + 1))))
				return (NULL);
			tab[cells][cols++][len] = '\0';
		}
		tab[cells++][columm] = NULL;
	}
	tab[line] = NULL;
	return (tab);
}

void			ft_print_triple_tab(char ***tab)
{
	int			i;
	int			j;

	if (!tab || !(*tab) || !(**tab))
		return ;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putstr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void			ft_delete_triple_tab(char ***tab)
{
	int			i;
	int			j;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			free(tab[i][j]);
			j++;
		}
		free(tab[i]);
		i++;
	}
	free(tab);
}
