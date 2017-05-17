/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_y.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 15:59:33 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/17 04:47:27 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

int 	k_ctrl_y(t_editline *editline, t_history *history)
{
	int save_position;
	char *ptr_start;
	char *ptr_end;
	int len_line;

	//printf("HERE\n");
	if (!editline->strcpy || !editline->temp)
	{
		//printf("return (1)\n");
		return (1);
	}
	//printf("par la\n");
	save_position = editline->pos;
	ft_putstr(editline->strcpy);
	if (*editline->temp)
		ft_putstr(*editline->temp + editline->pos);
	//else
		//return (1);
	//printf("test1\n");
//	//printf("\nline:%d => '%c'\tlen:%zu\n", line[0][0], line[0][0], ft_strlen(*line));
//	//printf("\n*pos:%d\n", *pos);
//	//printf("Global if:%d\n", (!(!*pos && !**line) && *cut == key_u) || (*cut == key_k && *pos != (int)ft_strlen(*line)) || (*cut == 0 && *pos != (int)ft_strlen(*line)));
//	//printf("if 1:%d\n", !(!*pos && !**line) && *cut == key_u);
//	//printf("if 2:%d\n", *cut == key_k && *pos != (int)ft_strlen(*line));
//	//printf("if 3:%d\n", (*cut == 0 && *pos != (int)ft_strlen(*line)));
//	//printf("*cut:%d\n", *cut);
	len_line = (int)ft_strlen(*editline->temp);
	//printf("test1-1\n");
	if ((!(!editline->pos && (*editline->temp && !**editline->temp)) && editline->cut == key_u) ||
		(editline->cut == key_k && editline->pos != len_line) || (editline->cut == 0 && editline->pos != len_line))
		tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(*editline->temp + editline->pos)), AFFCNT, &my_putchar);
	{
	//printf("test1-2\n");
	editline->pos += ft_strlen(editline->strcpy);
	//printf("test2\n");
}
	if (save_position == 0)
	{
		if (!*editline->temp)
		{
			*editline->temp = ft_strdup(editline->strcpy);
		}
		else
		{
			ptr_end = ft_strdup(*editline->temp);
			free(*editline->temp);
			if (!(*editline->temp = ft_strjoin(editline->strcpy, ptr_end)))
			{
				free(ptr_end);
				return (1);
			}
			free(ptr_end);
		}
	}
	else
	{
		if (!(ptr_start = ft_strsub(*editline->temp, 0, save_position)))
			return (1);
		if (!(ptr_end = ft_strdup(*editline->temp + save_position)))
		{
			free(ptr_start);
			return (1);
		}
		free(*editline->temp);
		if (!(*editline->temp = ft_str3join(ptr_start, editline->strcpy, ptr_end)))
		{
			free(ptr_start);
			free(ptr_end);
			return (1);
		}
		free(ptr_start);
		free(ptr_end);
	}
	editline->cut = 0;
	if (history->ret && history->history_cur)
		((t_history_elem*)((history->history_cur)->content))->flag_modif = 1;
	return (1);
}

