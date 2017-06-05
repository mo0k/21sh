/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 00:56:04 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/01 15:23:24 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

int		get_quoting_word(t_tokenizer *tknizer, char **ptr_begin, char **ptr_end)
{
	char c;

	printf("DEBUG | BEGIN get_quoting_word\n");
	if (!tknizer || !ptr_begin || !*ptr_begin || !ptr_end || !*ptr_end)
	{
		printf("DEBUG | 	return (0) get_quoting_word\n");
		return (0);
	}
	printf("*begin:\t%c\t%d\t%p\t%s\n", **ptr_begin, **ptr_begin,*ptr_begin,  *ptr_begin);
	printf("ptr_end:\t%c\t%d\t%p\n", **ptr_end, **ptr_end, *ptr_end);
	c = **ptr_end;
	**ptr_end = 0;
	//if (*ptr_begin != *ptr_end)
		get_word(&tknizer->token, ptr_begin, *ptr_end);
	**ptr_end = c;
	*ptr_begin = *ptr_end;
	if (ft_strlen(*ptr_end) >= 1)
	{
		printf("DEBUG | increment *ptr_end=>strlen(*ptr_end)=%d\n", (int)ft_strlen(*ptr_end));
		printf("%c\t%d\t%p__1\n", **ptr_end,**ptr_end, *ptr_end);
		(*ptr_end)++;
	}
	while (ptr_end && *ptr_end && **ptr_end && **ptr_end != c)
	{
		printf("%c\t%d\t%p__2\n", **ptr_end,**ptr_end, *ptr_end);
		(*ptr_end)++;
	}
	printf("%c\t%d\t%p__3\n", **ptr_end,**ptr_end, *ptr_end);
	if (**ptr_begin != 0)
	{
		(*ptr_end)++;
		printf("%c\t%d\t%p__4\n", **ptr_end,**ptr_end, *ptr_end);
		c = **ptr_end;
		**ptr_end = 0;
		printf("par la 2\n");
		create_token(&tknizer->token, *ptr_begin, word);
		printf("char temp:\t%c\t%d\t%p\n", c, c, &c);
		**ptr_end = c;
		printf("*ptr_end:\t%c\t%d\t%p\n", **ptr_end, **ptr_end, *ptr_end);
	}
	*ptr_begin = *ptr_end;
	printf("*begin:\t%c\t%d\t%p\t%s\n", **ptr_begin, **ptr_begin,*ptr_begin,  *ptr_begin);
	return (1);
}
