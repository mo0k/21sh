/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:44:28 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/03 23:14:12 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWLINE_H
# define NEWLINE_H

# include <readline.h>

void	init_newline(t_readline *readline);
int 	getn_newline(const char *line);
int		newline_readline_handler(int key, t_readline *readline);

#endif