/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 22:01:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/11 10:30:11 by mo0ky            ###   ########.fr       */
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
	create_token(atoken, *begin, WORD);
	*end = c;
	*begin = end + 1;
	return (1);
}

void 		get_word(t_list **atoken ,char **begin, char *end)
{
	printf("START find_word\n");
	char	*cur;
	int		state;
	int switcher;

	if (!atoken || !begin || !*begin || !end)
	{
		printf("return ;\n");
		return ;
	}
	switcher = 1;
	state = 0;
	cur = *begin;
	while (cur < end)// && *cur != 34 && *cur != 39)
	{

		printf("in while char:%c\t%d\t%p\t%p\t%d\n", *cur, *cur, cur, end, state);
		if (*cur == '\\')
		{
			cur++;
			printf("cas:\\ cur++\n");
		}
		else if (*cur == 34 || *cur == 39)
		{
			state = (switcher % 2) ? -1 : 1;
			printf("changement state:%d\n", state);
		}
		else if (*cur == '\\')
			cur++;
		//else if ((state > 0 && *cur == 0x20 && cur > *begin && *(cur - 1) != '\\') ||
		//	(state > 0 && *cur == 0x20 && cur > *begin + 1 && *(cur - 1) != '\\' && *(cur - 2) != '\\'))
		else if (state > 0 && *cur == 0x20)
		{
			printf("avant create_word 1\n");
			create_word(atoken, begin, cur);
			state = 0;
		}
		else if (*cur != 0x20)
		{
			printf("*cur != ' '\n");
			if (state == 0){
			printf("state = 1\n");
				state = 1;
			}
		}
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

