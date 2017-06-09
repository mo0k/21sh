/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 09:32:18 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/08 15:10:31 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>
//NO USE
static int 	liberate_nstack(char *stack, size_t n)
{
	printf("start liberate_nstack\n");
	int	i;

	i = 0;
	if (!stack)
		return (0);
	printf("%s\n", stack);
	while (stack[n])
	{
		printf("stack[%d](%c) = stack[%zu](%c)\n", i, stack[i], n, stack[n]);
		stack[i] = stack[n];
		n++;
		i++;
	}
	ft_strclr(stack + i);
	return (1);
}

static int 	fill_stack(char *stack, char *buffer, char *chars)
{
	//char *ptr;
	//char c;
	int i;

	if (!stack || !buffer || !*buffer)
		return (0);
	//ft_strclr(stack);
	//ptr = buffer;
	i = 0;
	while (i < 4096 && *buffer)
	{
		printf("*buffer:%c, char[0]:%c, char[1]:%c, !chars[1]:%d\n", *buffer, chars[0], chars[1], !chars[1]);
		if (chars[1] && (*buffer == chars[0] || *buffer == chars[1]))
		{
			printf("par la\n");
			stack[i++] = *buffer;
		}
		else if (!chars[1] && *buffer == chars[0])
			stack[i++] = *buffer;
		buffer++;
	}
	if (i == 4096)
		printf("stack full\n");
	stack[i] = 0;
	return (1);
}

static int 	read_stack(char *stack, char **line)
{
	int	i;
	int flag;
	char c;

	i = 0;
	flag = 0;
	c = 0;
	if (!stack || !line || !*line)
	{
		printf("return (0) read_stack\n");
		return (0);
	}
	while (stack[i])
	{
		printf("stack[%d]:%c, %d, %s\n", i, stack[i], stack[i], &stack[i]);
		if (!flag)
		{
			printf("flag == 0 => define char\n");
			c = stack[i];
			flag = 1;
			printf("c = %c %d\n", stack[i], stack[i]);
		}
		else if (stack[i] == c)
		{
			printf("go liberate\n");
			liberate_nstack(stack, i + 1);
			i = -1;
			flag = 0;
		}
		printf("_________________________\n");
		i++;
	}
	printf("end *stack:%c, %d\n", *stack, *stack);
	return (1);
}


void	check_stack(char **line, char *chars)
{
	printf("DEBUG | START quoting\n");
	char stack[4096];

	if (!line || !*line)
		return ;
	ft_strclr(stack);
	fill_stack(stack, *line, chars);
	printf("DEBUG | APRES fill_stack => stack:%s\n", stack);
	read_stack(stack, line);
	printf("DEBUG | APRES read_stack => stack:%s\n", stack);
	if (!*stack)
		return ;
	int chr;
	t_readline r;
	int ret = 2;
	char *join;

	init_newline(&r);
	r.temp = &r.line;

	//ft_addchar(line, '\n');
	//ft_putstr(PROMPT_NEWLINE);

	while (*stack)
	{
		//printf("DEBUG | in while *stack\n");
		chr = 0;
		if (ret == 2)
		{
			ft_addchar(line, '\n');
			ft_putstr(PROMPT_NEWLINE);

		}
		if (read(0, &chr, sizeof(int)) > 0)
		{
			if ((ret = newline_readline_handler(chr, &r)) == 2)
			{
				if (!r.line)
					ft_addchar(&r.line, '\n');
				printf("OEL\n");
				printf("DEBUG | in WHILE => newline:%s\n", r.line);
				if (!(join = ft_strjoin(*line, r.line)))
				{
					//free(r.line);
					return ;
				}
				printf("DEBUG | in WHILE => join:%s\n", join);
				free(*line);
				*line = join;
				printf("DEBUG | in WHILE => line:%s\n", *line);
				fill_stack(stack + ft_strlen(stack), r.line, chars);
				printf("DEBUG | in WHILE APRES fill_stack => stack:%s\n", stack);
				read_stack(stack, line);
				printf("DEBUG | in WHILE APRES read_line => stack:%s\n", stack);
				free(r.line);
				r.line = NULL;
				r.pos = 0;
				//return ;
			}
		}
	}
}

void	quoting(char **line)
{
	char c[2];

	c[0] = 34;
	c[1] = 39;
	//c[0] = '\\';
	//c[1] = 0;
	check_stack(line, c);
}
