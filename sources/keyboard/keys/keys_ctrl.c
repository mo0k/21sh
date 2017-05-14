/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 15:59:33 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/14 22:37:41 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

int 	key_ctrl_y(char **line, int *pos, char **strcpy)
{
	(void)line;
	(void)pos;
	//INVERSER CAD modfier *line avec *strcpy puis afficher et repositionner cursor
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	if (!strcpy || !*strcpy)
		return (1);
	ft_putstr(*strcpy);
	if (line && *line)
		ft_putstr(*line);
	if (*(*line) != 0)
		tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(*line)), AFFCNT, &my_putchar);
	if (*(*line) == 0)
	{
		free(*line);
		*line = ft_strdup(*strcpy);
	}

	return (1);
}

int 	key_ctrl_u(char **line, int *pos, char **strcpy)
{
	char *temp;

	if (strcpy && *strcpy)
		free(*strcpy);
	if (!(*strcpy = ft_strsub(*line, 0, *pos)))
		return (1);
	if (*pos)
		tputs(tgoto(tgetstr("LE", NULL), 1, *pos), AFFCNT, &my_putchar);
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(*line + *pos);
	if (!(temp = ft_strdup(*line + *pos)))
		return (1);
	free(*line);
	if (!(*line = ft_strdup(temp)))
	{
		free(temp);
		return (1);
	}
	free(temp);
	*pos = ft_strlen(*line);
	if (*pos)
		tputs(tgoto(tgetstr("LE", NULL), 1, *pos), AFFCNT, &my_putchar);
	*pos = 0;
	return (1);
}

int 	key_ctrl_k(char **line, int *pos, char **strcpy)
{
	(void)line;
	(void)pos;
	(void)strcpy;
	return (1);
}

int 	key_ctrl_w(char **line, int *pos, char **strcpy)
{
	(void)line;
	(void)pos;
	(void)strcpy;
	return (1);
}
