/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:32 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/17 06:10:59 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

void	keyboard_handler(char *buff, t_editline *editline)
{
	if (((stock_data(NULL)->history).ret || IS_K_ARROW_UP(buff) ||
		((stock_data(NULL)->history).ret && IS_K_ARROW_DOWN(buff))) && (stock_data(NULL)->history).history_cur)
		editline->temp = &(((t_history_elem*)(((stock_data(NULL)->history).history_cur)->content))->value);
	else
		editline->temp = &editline->line;
	//printf("%d %d %d %d %d %d\n", buff[0], buff[1], buff[2], buff[3], buff[4], buff[5]);
	if (is_arrow_keys(buff, editline, &stock_data(NULL)->history))
		return ;
	else if (editline->temp && is_home_or_end_keys(buff, *editline->temp, &editline->pos))
		return ;
	else if (is_dels_keys(buff, editline->temp , &editline->pos, &stock_data(NULL)->history))
		return ;
	else if (is_ctrl_keys(buff,  editline, &stock_data(NULL)->history))
		return ;
	else if (is_alt_keys(buff, *editline->temp, &editline->pos))
		return ;
	else if (IS_K_RETURN(buff)) //ENTER
	{
		printf("\n%p:line:%s\tpos:%d\n", *editline->temp ,*editline->temp, editline->pos);
		k_return(editline->temp, &stock_data(NULL)->history);
		reset_line(&editline->line, &editline->pos);
		prompt(&stock_data(NULL)->prompt);
	}
	else if (ft_isprint(buff[0]))
	{
		add_key(buff[0], &stock_data(NULL)->history, editline);
	}
}
