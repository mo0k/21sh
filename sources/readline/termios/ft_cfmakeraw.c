/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cfmakeraw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:30:40 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/19 18:50:51 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <terms.h>

void	ft_cfmakeraw(t_termios *conf)
{
	if (!conf)
		return ;
	conf->c_iflag &= ~(IMAXBEL | IGNBRK | BRKINT | PARMRK | ISTRIP |
			INLCR | IGNCR | ICRNL | IXON);
	conf->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	conf->c_cflag &= ~(CSIZE | PARENB);
	conf->c_cflag |= CS8;
	conf->c_cc[VMIN] = 1;
	conf->c_cc[VTIME] = 0;
}