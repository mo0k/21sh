/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 20:28:25 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 22:42:22 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_21sh.h>

t_shell	*stock_data(t_shell *elem)
{
	static t_shell *tmp;

	if (elem)
		tmp = elem;
	else
		return (tmp);
	return (elem);
}

void	print_stock(t_shell *stock)
{
	fprintf(stdout, "STOCK(%p)\n", stock);
	fprintf(stdout, "readline(%p):\n\tline(%p):%s\n", &stock->readline, (stock->readline).line, (stock->readline).line);
	fprintf(stdout, "WIN(%p):\n\tcol:%d\n\trow:%d\n",&stock->readline.win, (stock->readline.win).col, (stock->readline.win).row);
	fprintf(stdout, "HISTORY(%p):\n\t&history_root:%p\thistory_root:%p\n", &stock->history, &((stock->history).history_root), (stock->history).history_root);
	fprintf(stdout, "              \t&history_cur:%p\thistory_cur:%p\n",&((stock->history).history_cur), (stock->history).history_cur);
}