/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:28:31 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/07 22:25:21 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include <fcntl.h>
# include <libft.h>

typedef struct	s_history_elem
{
	char		*value;
	char		*save;
	int			flag_new;
	int			flag_modif;
}				t_history_elem;

typedef struct	s_history
{
	t_list		*history_root;
	t_list		*history_cur;
	int 		ret;
	int 		in;
}				t_history;

enum e_move
{
	up,
	down,
	right,
	left,
	home,
	end
};

# include <ft_21sh.h>

void	init_history(t_history *history);
void	init_elem_history(t_history_elem *e, char *val, int f_new, int f_modif);
void	print_history_elem(t_list *elem);
void	del_history_elem(void *content, size_t size);
int 	save_history(t_list *history);
int		load_history(t_list **history);
int 	move_history(t_list **history, int *state, enum e_move move, t_editline *editline);
//int 	move_up(t_list **history, t_editline *editline);
//int 	move_down(t_list **history, t_editline *editline);


#endif