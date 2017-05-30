/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 22:01:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/31 00:37:33 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

static int	create_word(t_list **atoken ,char **begin, char *end)
{
	char	c;

	if (!atoken || !begin || !*begin || !end)
		return (0);
	c = *end;
	*end = 0;
	create_token(atoken, *begin, word);
	*end = c;
	*begin = end + 1;
	return (1);
}

void 		get_word(t_list **atoken ,char **begin, char *end)
{
	printf("START find_word\n");
	char	*cur;
	int		state;

	if (!atoken || !begin || !*begin || !end)
		return ;
	state = 0;
	cur = *begin;
	while (cur < end)
	{
		printf("in while char:%c\n", *cur);
		if (state && *cur == 0x20)
		{
			printf("avant create_word 1\n");
			create_word(atoken, begin, cur);
			state = 0;
		}
		else if (*cur != 0x20)
			state = 1;
		cur++;
	}
	if (state)
	{
		printf("avant create_word 2\n");
		create_word(atoken, begin, cur);
		state = 0;
	}
	printf("return (1) end function\n");
}
