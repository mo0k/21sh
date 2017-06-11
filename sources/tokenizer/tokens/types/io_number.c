/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 22:01:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/10 16:43:45 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

int		is_io_number(char *ptr_begin, char *ptr_end)
{
	printf("DEBUG | BEGIN is_io_number\n");
	int state;

	state = 0;
	if (!ptr_begin || !ptr_begin)
		return (0);
	printf("DEBUG | 1 char:%d\n", *ptr_end);
	printf("DEBUG | begin:%p\tend:%p\n", ptr_begin, ptr_end);
	if (ptr_end > ptr_begin)
		--ptr_end;
	printf("DEBUG | 2 char:%d\n", *ptr_end);
	printf("DEBUG | begin:%p\tend:%p\n", ptr_begin, ptr_end);
	while (ptr_end >= ptr_begin)
	{
		printf("DEBUG | begin:%p\tend:%p\n", ptr_begin, ptr_end);
		printf("DEBUG | 3 char:%d\n", *ptr_end);
		if (*ptr_end > 47 && *ptr_end < 58)
		{
			printf("DEBUG | decrementation\n");
			state = 1;
			--ptr_end;
		}
		else if (state && *ptr_end == 32 && ptr_end > ptr_begin && *(ptr_end - 1) != '\\') // ajouter condition for 
			return (1);
		else
			return (0);
	}
	printf("DEBUG | END state:%d\n", state);
	if (state)
		return (1);
	else
		return (0);
}

static char	*find_io_number(char *ptr_begin, char *ptr_end)
{
	char *begin;

	if (!ptr_begin || !ptr_end)
		return (NULL);
	begin = ptr_end;
	while (begin >= ptr_begin)
	{
		if (begin == ptr_begin || (*begin == ' ' && begin > ptr_begin && *(begin - 1) != '\\'))
			break;
		begin--;
	}
	return (begin);
}

void	get_io_number(t_list **tokens, char **begin, char *end)
{
	printf("IO_NUMBER\n");
	char *temp;
	char c;

	if (!tokens || !begin || !*begin || !end)
		return ;
	if (!(temp = find_io_number(*begin, end)))
		return ;
	c = *temp;
	*temp = 0;
	get_word(tokens, begin, temp);
	*temp = c;
	if (end >= temp && *temp != 0 && !is_special_char(*temp))
	{
		c = *end;
		*end = 0;
		create_token(tokens, temp, IO_NUMBER);
		*end = c;
	}
}