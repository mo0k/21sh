/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 19:54:01 by mo0ky             #+#    #+#             */
/*   Updated: 2017/04/29 13:04:35 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_GETENV "Environnement TERM no define"
# define ERR_TGETENT_NOFOUND "The terminfo database could not be found"
# define ERR_TGETENT_NOENTRY "There is no such entry for TERM value"
# define ERR_TCGETATTR "Impossible to copy the parameters associated with the terminal referenced"
# define ERR_WINSIZE "Terminal width is too small"

void		ft_fatal(char *error);

#endif