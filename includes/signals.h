/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:01:02 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/14 16:48:11 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_SIGNALS_H
# define MANAGE_SIGNALS_H

# include <ft_21sh.h>
# include <signal.h>

void		catch_signals(void);
void		handler_signals(int sig);
void		handler_paste(int sig);

#endif