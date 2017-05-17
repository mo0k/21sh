/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:28:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/16 23:07:12 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>


static int 	move_up(t_list **history, t_editline *editline)
{
	//printf("move UP\n");
	//if (!history)
	//	return (0);
		if ((*history)->prev)
		{
			*history = (*history)->prev;
		//	printf("PAR LA\n");
			if (editline->pos > 0)
				tputs(tgoto(tgetstr("LE", NULL), 0, editline->pos), AFFCNT, &my_putchar);
			tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
			ft_putstr(((t_history_elem*)((*history)->content))->value);
			//free(editline->line);
			//editline->line = ft_strdup(((t_history*)(current->content))->value);
			//*history = *current;
			editline->temp = &((t_history_elem*)((*history)->content))->value;
			(editline->pos) = ft_strlen(*editline->temp);
			return (1);
		}
		else
		{
			ft_putchar(7);
			return(1);
		}
}

static int 	move_down(t_list **history, t_editline *editline)
{
	//printf("move DOWN\n");
	if (!history || !*history || !editline)
		return (0);
	if (*history && (*history)->next)
	{
		//printf("PAR ICI\n");
		*history = (*history)->next;
		if (editline->pos > 0)
			tputs(tgoto(tgetstr("LE", NULL), 0, editline->pos), AFFCNT, &my_putchar);
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		ft_putstr(((t_history_elem*)((*history)->content))->value);
		//free(*editline->temp);
			//*editline->temp = ft_strdup(((t_history*)(current->content))->value);
			//*history = *current;
		editline->temp = &((t_history_elem*)((*history)->content))->value;
		(editline->pos) = ft_strlen(*editline->temp);
		return (1);
	}
	else
	{
		//ft_putchar(7);
		return (0);
			//if (!buffer_tmp)
		/*if (((t_history*)((*current)->content))->flag_new == 1)
			ft_putchar(7);
		else
		{
			*editline->temp = ft_strnew(1);
			//(*(*editline->temp) = buff[0]);
			t_history new;
			t_list *tmp;

			init_elem_history(&new, *editline->temp, 1, 0);
			ft_lstadd_end(history, (tmp = ft_lstnew(&new, sizeof(t_history))));
			free(*editline->temp);
			*history = tmp;
			*editline->temp = ((t_history*)(tmp->content))->value;
		}
			else
			{
				if (editline->pos > 0)
					tputs(tgoto(tgetstr("LE", NULL), 0, editline->pos), AFFCNT, &my_putchar);
				tputs(tgetstr("ce", NULL), AFFCNT, &my_putchar);
				ft_putstr(buffer_tmp);
				free(*buff);
				*buff = ft_strdup(buffer_tmp);
				(editline->pos) = ft_strlen(*buff);
			}*/
		}
}

int 		move_history(t_list **history, int *state, enum e_move move, t_editline *editline)
{
	//printf("PAR LAAAAAAAA\n");
	if (!history || !*history || !editline)
	{
		if (!*history)
			ft_putchar(7);
	//	printf("return (0);\n");
		return (0);
	}
	/*if (!current)
	{
		current = *history;
		state = 1;
		while (current && current->next)
			current = current->next;
	}*/
	if (!*state)
	{
		while (*history && (*history)->next)
			*history = (*history)->next;
		*state = 1;
	}
	//printf("%s\n", ((t_history*)(current->content))->value);
	if (*state == 1 && move == up)
	{
		if (editline->pos > 0)
				tputs(tgoto(tgetstr("LE", NULL), 0, editline->pos), AFFCNT, &my_putchar);
			tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
			//printf("pos:%d\n", editline->pos);
			//ft_putstr(((t_history*)((current)->content))->value);
			ft_putstr(((t_history_elem*)((*history)->content))->value);
			//free(*editline->temp);
			//*editline->temp = ft_strdup(((t_history_elem*)(current->content))->value);
			//*history = current;
			editline->temp = &((t_history_elem*)((*history)->content))->value;
			(editline->pos) = ft_strlen(*editline->temp);
		*state = 2;
	}
	else if (move == up)
		return (move_up(history, editline));
	else if (move == down)
	{
		int ret = move_down(history, editline);
		(!ret) ? (*state = 1) : 1;
		return (ret);
	}
	return (1);
}