/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:05:08 by mo0ky             #+#    #+#             */
/*   Updated: 2017/07/03 10:49:41 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_21sh.h>

static void	catch_newline_and_tab(char *value)
{
	int i;

	if (!value)
		return ;
	i = 0;
	while (value[i])
	{
		if (value[i] == '\t' || value[i] == '\n')
			value[i] = ' ';
		i++;
	}

}

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

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	//char 	buff[4];
	t_shell		shell;
	int			chr;
	int			r;

	r = 2;
	init(&shell, env);
	catch_signals();
	stock_data(&shell);
	print_stock(&shell);
	//
	//ft_lstiter(shell.history, &print_history_elem);
	//
	printf("DEBUG | 1 in_newline:%d\n", shell.readline.in_newline);
	while (42)
	{
		chr = 0;
		if (r > 1)
			prompt(shell.readline.prompt.val);
		if (read(0, &chr, sizeof(int)) > 0)
		{
			if ((r = readline_handler(chr, &shell.readline, &shell.history)) == 2)
			{
				if (tokenizer(&shell.tokenizer, ((t_history_elem*)(shell.history.history_cur->content))->val))
				{
					printf("GO PARSER\n");
					//si tokenizer return 1 start parsing
					if (parser(&shell.tokenizer.token, &shell.parameters))
					{
						printf("OK PARSER\n");
						printf("GO create ast");
					}
				}
				catch_newline_and_tab(((t_history_elem*)(shell.history.history_cur->content))->val);
				delete_tokens(&shell.tokenizer.token);
			}
		}
	}
	return (0);
}