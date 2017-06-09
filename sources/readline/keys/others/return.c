/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:11:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/08 15:06:52 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>
/*
static void	catch_newline(char *value)
{
	int i;

	if (!value)
		return ;
	i = 0;
	while (value[i])
	{
		if (value[i] == '\n' || value[i] == '\t')
			value[i] = ' ';
		i++;
	}

}
*/
int 	k_return(char **line, t_history *history)
{
		t_list			*new;
		t_history_elem	*content;
		t_history_elem	elem;
		int				state;
		t_protect		ret;
	printf("DEBUG | start k_return\n");
		state = 0;
		if (!line || !*line || !history)
		{
			printf("DEBUG | return (0)\n");
			return (3);
		}
		init_elem_history(&elem, *line, 1, 0);
		if (!history->history_root)
			state = 1;
		ft_lstadd_end(&history->history_root, (new = ft_lstnew(&elem, sizeof(t_history_elem))));
		//CHECK QUOTING BEFORE VALID LINE AFTER HISTORY
		while ((ret = check_protection(((t_history_elem*)(new->content))->value)) < 0)
		{
			//afficher prompt && recupere nouvelle ligne pour ajouter
			// a la value de history et repasser au check_protection
			printf("line:%s\n", ((t_history_elem*)(new->content))->value);
			get_newline(&((t_history_elem*)(new->content))->value);
			printf("ret:%d\n", ret);
		}
			//catch_newline(((t_history_elem*)(new->content))->value);
		//quoting(&((t_history_elem*)(new->content))->value);
		//END OF CHECK
		if (state)
			history->history_cur = history->history_root;
		if (history->ret)
		{
			content = ((t_history_elem*)((history->history_cur)->content));
			history->history_cur = new;
			if (content->flag_modif == 1)
			{
				content->flag_modif = 0;
				free(content->value);
				content->value = ft_strdup(content->save);
			}
			history->in = 0;
			history->ret = 0;
		}
		history->history_cur = new;




		ft_lstiter(history->history_root, &print_history_elem);
		//print_stock(stock_data(NULL));
		//////////////////////////////////////////////////////////////
		///
		///				TEST BUILT-IN
		///
		///
		///////////////////////////////////////////////////////////
		if (line && *line && !ft_strcmp(*line, "exit"))
		{
			printf("|||||||||||||||||||||||||||||||||||||||||\n");
			ft_lstiter(history->history_root, &print_history_elem);
			save_history(history->history_root);
			restore_config(stock_data(NULL)->termios.origin);
			exit(EXIT_SUCCESS);
		}
		else if (line && *line && !ft_strcmp(*line, "history -C"))
		{
			printf("|||||||||||||||||||||||||||||||||||||||||\n");
			history->history_cur = history->history_root;
			while (history->history_cur)
			{
				ft_lstdelfirst(&history->history_cur, &del_history_elem);
				history->history_cur = history->history_cur->next;
			}
			printf("DEBUG | history_cur:%p\n", history->history_cur);
			history->history_root = NULL;
			printf("DEBUG | AVANT PRINT STOCK -c\n");
			print_stock(stock_data(NULL));
			printf("DEBUG | FIN history -c\n");
			return (3);
		}
		return (2);
}
