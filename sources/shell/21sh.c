/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:05:08 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 00:52:02 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_21sh.h>

static void		*ft_ec_malloc(unsigned int size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		ft_fatal("in ft_ec_malloc on memory allocation");
	return(ptr);
}

int 	ft_delchar(char **str, int pos)
{
	int 	len;
	char	*new;

	if (!str || !*str)
		return (0);
	len = ft_strlen(*str);
	new = (char *)ft_ec_malloc(sizeof(char) * len);
	ft_bzero(new, len);
	new[len] = 0;
	if (pos > len)
		return (0);
	new = ft_strncpy(new, *str, pos);
	new = ft_strcat(new, (*str) + pos + 1);
	free(*str);
	*str = new;
	return (1);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	//char 	buff[4];
	t_shell		shell;

	init(&shell);
	catch_signals();
	stock_data(&shell);
	print_stock(&shell);
	prompt(shell.prompt.val);
	//
	//ft_lstiter(shell.history, &print_history_elem);
	//
	int				chr;
	while (42)
	{
	chr = 0;
		if (read(0, &chr, sizeof(int)) > 0)
			readline_handler(chr, &shell);
		//return (chr);
		//ft_memset(buff, 0, 4);
		//if (read(STDIN_FILENO, &buff, 4) > 0)
			//keyboard_handler(chr, &shell.editline);
	}
	return (0);
}