/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 11:01:20 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/17 23:44:43 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void		remove_backslash(char **astr, char **aptr)
{
	if (!astr || !*astr || !aptr || !*aptr)
		return ;
	(*astr)++;
	//printf("4 association **aptr = **astr =>  '%c'='%c'\n", **aptr, **astr);
	if (**astr != '\n')
	{
		**aptr = **astr;
		(*aptr)++;
	}
	//(*astr)++;
	
}