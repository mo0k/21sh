/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:44:28 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/18 13:59:45 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWLINE_H
# define NEWLINE_H

# include <readline.h>

void	init_newline(t_readline *readline);
//int 	getn_newline(const char *line);
//int 	get_newline(char **line);
int 	get_newline(char **line, t_history *h);//, int *in_newline);
int		newline_handler(int key, t_readline *readline);

#endif