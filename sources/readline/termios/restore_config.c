/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:30:40 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/19 18:54:28 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <terms.h>

int			restore_config(t_termios *origin)
{
	if (tcsetattr(0, TCSADRAIN, origin) == -1)
		exit(EXIT_FAILURE);
	return (1);
}
