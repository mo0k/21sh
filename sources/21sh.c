/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:05:08 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/07 22:55:38 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_21sh.h>

void	print_stock(t_shell *stock)
{
	fprintf(stdout, "STOCK(%p)\n", stock);
	fprintf(stdout, "EDITLINE(%p):\n\tline(%p):%s\n", &stock->editline, (stock->editline).line, (stock->editline).line);
	fprintf(stdout, "WINSIZE(%p):\n\tcol:%d\n\trow:%d\n",&stock->winsize, (stock->winsize).col, (stock->winsize).row);
	fprintf(stdout, "HISTORY(%p):\n\t&history_root:%p\thistory_root:%p\n", &stock->history, &((stock->history).history_root), (stock->history).history_root);
	fprintf(stdout, "              \t&history_cur:%p\thistory_cur:%p\n",&((stock->history).history_cur), (stock->history).history_cur);
}

static void		*ft_ec_malloc(unsigned int size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		ft_fatal("in ft_ec_malloc on memory allocation");
	return(ptr);
}

int 	delchar(char **str, int pos)
{
	int 	len;
	char	*new;

	if (!str || !*str)
	{
		printf("return 0\n");
		return (0);
	}
	len = ft_strlen(*str);
	new = (char *)ft_ec_malloc(sizeof(char) * len);
	ft_bzero(new, len);
	new[len] = 0;
	if (pos > len)
	{
		printf("return 0\n");
		return (0);
	}
	//printf("DEBUG:%s\t%s\n", *str, (*str) + pos + 1);
	new = ft_strncpy(new, *str, pos);
	//printf("DEBUG:%s\n", new);
	new = ft_strcat(new, (*str) + pos + 1);
	free(*str);
	*str = new;
	//printf("new:%s\n", new);
	//printf("new:%s\n", *str);
	return (1);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char 	buff[6];
	t_shell		shell;

	init(&shell);
	catch_signals();
	stock_data(&shell);
	print_stock(&shell);
	prompt();
	//
	//ft_lstiter(shell.history, &print_history_elem);
	//
	while (42)
	{
		ft_memset(buff, 0, 6);
		read(STDIN_FILENO, &buff, 6);
		keyboard_handler(buff, &shell.editline);
	}
	return (0);
}