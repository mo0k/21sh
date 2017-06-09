/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:39:56 by jmoucade          #+#    #+#             */
/*   Updated: 2017/06/08 15:21:59 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

static int	do_quoting(char **astr, char c)
{
	if (!astr || !*astr)
		return (0);
	(*astr)++;
	while (**astr && **astr != c)
		(*astr)++;
	if (**astr == c)
		return (1);
	else
		return ((c == '\'') ? quote : quotes);
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
			ret = do_quoting(&str, '\'');
		else if (*str == '\"')
			ret = do_quoting(&str, '\"');
		else if (*str == '\\' && *(str + 1) == 0)
			ret = backslack;
		else if (*str == '\\')
			str++;

		printf("ret:%d\n",ret);
		if (ret < 1)
			break;
		if (*str != 0)
			str++;
	}
	//return (!ret ? 0 : 1)
	if (ret < 1)
	{
		printf("DEBUG | NEWLINE\n");
		return (ret);
	}
	printf("DEBUG | OK\n");
	return (1);
}