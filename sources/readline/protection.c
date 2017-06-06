/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:39:56 by jmoucade          #+#    #+#             */
/*   Updated: 2017/06/06 18:55:47 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

static int	do_quoting(char *str, char c)
{
	if (!str)
		return (0);
	str++;
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (1);
	else
		return ((c == '\'') ? -1 : -2);
}
/*
**	
**
*/
int		check_protection(char *str)
{
	printf("DEBUG | start check_position\n");
	int ret;

	ret = 1;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\'')
			ret = do_quoting(str, '\'');
		else if (*str == '\"')
			ret = do_quoting(str, '\"');
		else if (*str == '\\' && *(str + 1) == 0)
			ret = -3;
		printf("ret:%d\n",ret);
		if (ret < 1)
			break;
		if (*str != 0)
			str++;
	}
	//return (!ret ? 0 : 1)
	if (ret < 1)
	{
		printf("DEBUG | PROBLEME\n");
		return (0);
	}
	printf("DEBUG | OK\n");
	return (1);
}