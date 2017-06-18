/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inhibitor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 21:47:57 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/17 23:24:38 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int		inhibitor(char *value)
{
	//printf("DEBUG | BEGIN inhibitor => value=%s\n", value);
	char	*ptr_cur;
	char	*ptr_new;
	int		state;

	if (!value)
		return (0);
	state = 0;
	ptr_cur = value;
	ptr_new = value;
	while (*ptr_cur)
	{
		//printf("while:*val:'%c'\t*ptr:'%c'\n", *ptr_cur, *ptr_new);
		if (*ptr_cur == '\'' && (state = 1))
			remove_quote(&ptr_cur, &ptr_new);
		else if (*ptr_cur == '\"' && (state = 1))
			remove_dquote(&ptr_cur, &ptr_new);
		else if (*ptr_cur == '\\' && (state = 1))
			remove_backslash(&ptr_cur, &ptr_new);
		else
		{
			//printf("5 association begin = end =>  '%c'='%c'\n", *ptr_new, *ptr_cur);
			*ptr_new = *ptr_cur;
			if (*ptr_new)
				ptr_new++;
		}
		if (*ptr_cur)
			ptr_cur++;
	}
	if (ptr_new != value)
	{
		//printf("add char NULL\n");
		*ptr_new = 0;
	}
	ft_putendlcolor("----------TOKEN----------", C_GREEN);
	printf("val:%s\n", value);
	ft_putendlcolor("-------------------------", C_GREEN);
	return (state ? 1 : 0);
}
