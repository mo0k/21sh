/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:28:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/17 05:02:07 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>

int			load_history(t_list **history)
{
	printf("start load history\n");
	int		fd;
	char	*line;

	if (!history)
		return (0);
	if ((fd = open("/Users/jmoucade/.21sh_history", O_RDONLY)) == -1)
	{
		ft_error("to load 21sh_history");
		return (0);
	}

	while (get_next_line(fd, &line))
	{
		t_history_elem new;

		init_elem_history(&new, line, 0, 0);
		ft_lstadd_end(history, ft_lstnew(&new, sizeof(t_history_elem)));
		free(line);
	}
	ft_lstiter(*history, &print_history_elem);
	close(fd);
	return (1);
}