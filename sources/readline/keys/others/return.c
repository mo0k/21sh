/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:11:47 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/19 16:09:13 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int 	k_return(char **line, t_history *history)//, int *in_newline)
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
		//history->history_cur = new;
			//catch_newline(((t_history_elem*)(new->content))->val);
		//quoting(&((t_history_elem*)(new->content))->val);
		//END OF CHECK
		printf("new:%p\n", new);
		while ((ret = check_protection(((t_history_elem*)(new->content))->val)) < 0)
		{
			//afficher prompt && recupere nouvelle ligne pour ajouter
			// a la val de history et repasser au check_protection
			printf("before line:%s\n", ((t_history_elem*)(new->content))->val);//, *in_newline);
			get_newline(&((t_history_elem*)(new->content))->val, history);//, in_newline);
			printf("after line:%s\n", ((t_history_elem*)(new->content))->val);//, *in_newline);
			printf("ret:%d\n", ret);
		}
		if (state)
		{
			printf("DEBUG | history->history_cur = history->history_root, %p\n", history->history_root);
			history->history_cur = history->history_root;
		}
		if (history->ret)
		{
			content = ((t_history_elem*)((history->history_cur)->content));
			//history->history_cur = new;
			if (content->flag_modif == 1)
			{
				content->flag_modif = 0;
				free(content->val);
				content->val = ft_strdup(content->save);
			}
			history->in = 0;
			history->ret = 0;
		}
		printf("DEBUG | history->history_cur = new, %p\n", new);
		history->history_cur = new;




		ft_lstiter(history->history_root, &print_history_elem);
		print_stock(stock_data(NULL));
		//////////////////////////////////////////////////////////////
		///
		///				TEST BUILT-IN
		///
		///
		///////////////////////////////////////////////////////////
		if (line && *line && !ft_strcmp(*line, "exit"))
		{
			printf("1 |||||||||||||||||||||||||||||||||||||||||\n");
			ft_lstiter(history->history_root, &print_history_elem);
			save_history(history->history_root);
			restore_config(stock_data(NULL)->termios.origin);
			exit(EXIT_SUCCESS);
		}
		else if (line && *line && !ft_strcmp(*line, "history -C"))
		{
			printf("2 |||||||||||||||||||||||||||||||||||||||||\n");
			history->history_cur = history->history_root;
			while (history->history_cur)
			{
				printf("DEBUG | 1 delete history => %p\n", history->history_cur);
				ft_lstdelfirst(&history->history_cur, &del_history_elem);
				printf("DEBUG | 2 delete history => %p\n", history->history_cur);
				if (history->history_cur)
					history->history_cur = history->history_cur->next;
			}
			printf("DEBUG|||\n");
			printf("DEBUG | history_cur:%p\n", history->history_cur);
			history->history_root = NULL;
			printf("DEBUG | AVANT PRINT STOCK -c\n");
			print_stock(stock_data(NULL));
			printf("DEBUG | FIN history -c\n");
			return (3);
		}
		else if (line && *line && !ft_strcmp(*line, "env"))
		{
			ft_lstiter(stock_data(NULL)->parameters.environment, &print_param_all);
			return (3);
		}
		return (2);
}
