/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 22:51:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/17 17:21:02 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	remove_quote(char **astr, char **aptr)
{
	//char *ptr;
	//printf("DEBUG | BEGIN do_quote\n");

	if (!astr || !*astr || !aptr || !*aptr )
		return ;
	//ptr = *astr;
	(*astr)++;
	while (**astr && **astr != '\'')
	{
		//printf("0 association **aptr = **astr =>  '%c'='%c'\n", **aptr, **astr);
		**aptr = **astr;
		(*astr)++;
		(*aptr)++;
	}
}

void	remove_dquote(char **astr, char **aptr)
{
	if (!astr || !*astr || !aptr || !*aptr )
		return ;
	//ptr = *astr;
	(*astr)++;
	while (**astr && **astr != '\"')
	{
		if (**astr == '\\' && *(*astr + 1) && *(*astr + 1) == '\"')// && (ptr == str || (str > ptr && *(str - 1) != '\\')))
		{
			//printf("1 association **aptr = **astr =>  '%c'='%c'\n", **aptr, *(*astr + 1));
			**aptr = *(*astr + 1);
			++(*aptr);
			(*astr) += 2;
		}
		else if (**astr == '\\' && *(*astr + 1) && *(*astr + 1) == '\\')// && (ptr == str || (str > ptr && *(str - 1) != '\\')))
		{
			//printf("2 association **aptr = **astr =>  '%c'='%c'\n", **aptr, *(*astr + 1));
			**aptr = *(*astr + 1);
			++(*aptr);
			(*astr) += 2;
		}
		else
		{
			//printf("3 association **aptr = **astr =>  '%c'='%c'\n", **aptr, **astr);
			**aptr = **astr;
			(*astr)++;
			(*aptr)++;
		}
	}
}
