/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 09:32:18 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/31 23:17:44 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

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

static int 	fill_stack(char *stack, char *buffer)
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
		if (*buffer == 34 || *buffer == 39)
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
	//if (!*stack)
	//	printf("QUOTING___________OK\n");
	//else
	//{
	//while (*stack)
	//{
		//char *quote_line;
		//char *join;
		//quote_line = 0;
		//restore_config(stock_data(NULL)->termios.origin);
		//ft_addchar(line, '\n');
		//printf("line:%s\n", *line);
		//ft_putstr("> ");
		//if (get_next_line(0, &quote_line))
		//{
			//printf("newline:%s\n", quote_line);
			//if (!(join = ft_strjoin(*line, quote_line)))
			//	return (0);
			//free(*line);
			//*line = join;
			//fill_stack(stack, quote_line);
			//free(quote_line);

		//}

		//init_config_term(stock_data(NULL)->termios.new, stock_data(NULL)->termios.origin);
		//printf("QUOTING___________KO_____do_while\n");
	//}
	return (1);
}


void	quoting(char **line)
{
	printf("DEBUG | START quoting\n");
	char stack[4096];


	if (!line || !*line)
		return ;
	ft_strclr(stack);
	fill_stack(stack, *line);
	printf("DEBUG | APRES fill_stack => stack:%s\n", stack);
	/*ptr = *line;
	i = 0;
	while (i < 4096 && *ptr)
	{
		if (*ptr == 34 || *ptr == 39)
			stack[i++] = *ptr;
		ptr++;
	}
	if (i == 4096)
		printf("stack full\n");
	stack[i] = 0;*/
	read_stack(stack, line);
	printf("DEBUG | APRES read_stack => stack:%s\n", stack);
	while (*stack)
	{
		printf("DEBUG | begin WHILE => stack:%s\n", stack);
		char *quote_line;
		char *join;
		quote_line = 0;
		restore_config(stock_data(NULL)->termios.origin);
		ft_addchar(line, '\n');
		printf("DEBUG | in WHILE => line:%s\n", *line);
		ft_putstr("> ");
		if (get_next_line(0, &quote_line))
		{
			printf("DEBUG | in WHILE => newline:%s\n", quote_line);
			if (!(join = ft_strjoin(*line, quote_line)))
			{
				free(line);
				return ;
			}
			printf("DEBUG | in WHILE => join:%s\n", join);
			free(*line);
			*line = join;
			printf("DEBUG | in WHILE => line:%s\n", *line);
			fill_stack(stack + ft_strlen(stack), quote_line);
			printf("DEBUG | in WHILE APRES fill_stack => stack:%s\n", stack);
			read_stack(stack, line);
			printf("DEBUG | in WHILE APRES read_line => stack:%s\n", stack);
			free(quote_line);
			
		}
		init_config_term(stock_data(NULL)->termios.new, stock_data(NULL)->termios.origin);
	printf("stack:%s\n", stack);
	}
}