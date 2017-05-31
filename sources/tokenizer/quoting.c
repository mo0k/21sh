/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 00:56:04 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/01 01:46:24 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

int		get_quoting_word(t_tokenizer *tknizer, char **ptr_begin, char *ptr_end)
{
	char c;

	printf("DEBUG | BEGIN get_quoting_word\n");
	if (!tknizer || !ptr_begin || !*ptr_begin || !ptr_end)
	{
		printf("DEBUG | 	return (0) get_quoting_word\n");
		return (0);
	}
	c = *ptr_end;
	*ptr_end = 0;
	//if (*ptr_begin != ptr_end)
		get_word(&tknizer->token, ptr_begin, ptr_end);
	*ptr_end = c;
	*ptr_begin = ptr_end;
	if (ft_strlen(ptr_end) >= 1)
		ptr_end++;
	while (ptr_end && *ptr_end && *ptr_end != c)
	{
		printf("%c\n", *ptr_end);
		ptr_end++;
	}
	if (**ptr_begin != 0)
	{
		ptr_end++;
		c = *ptr_end;
		*ptr_end = 0;
		printf("par la 2\n");
		create_token(&tknizer->token, *ptr_begin, word);
		*ptr_end = c;
	}
	*ptr_begin = ptr_end + 1;
	printf("%c-%d-%s\n", **ptr_begin, **ptr_begin, *ptr_begin);
	return (1);
}
