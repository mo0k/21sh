/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:11:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/19 22:35:01 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	k_return(char **line, t_history *history)
{
		t_list			*new;
		t_history_elem	*content;
		t_history_elem	elem;
		int				state;

		state = 0;
		if (!line || !*line || !history)
			return (0);
		init_elem_history(&elem, *line, 1, 0);
		if (!history->history_root)
			state = 1;
		ft_lstadd_end(&history->history_root, (new = ft_lstnew(&elem, sizeof(t_history_elem))));
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
			history->in = 1;
			history->ret = 0;
		}




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
			history->history_root = NULL;
			print_stock(stock_data(NULL));
		}
		return (1);
}
