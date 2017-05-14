/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_alt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:25:23 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/14 10:51:13 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>


int 	key_alt_up(int *pos, char *line)
{
	int len_prompt = (int)ft_strlen(stock_data(NULL)->prompt) + 3;
	int cols = (int)(stock_data(NULL)->winsize).col;
	(void)line;

	if (len_prompt + *pos > cols)
	{
		if (*pos + 1 - (cols - len_prompt) > len_prompt)
		{
			tputs(tgetstr("up", NULL), AFFCNT, &my_putchar);
			*pos -= cols;
		}
		else
		{
			tputs(tgoto(tgetstr("LE", NULL), 1, *pos - (cols - len_prompt)), AFFCNT, &my_putchar);
			tputs(tgetstr("up", NULL), AFFCNT, &my_putchar);
			tputs(tgoto(tgetstr("RI", NULL), 1, len_prompt), AFFCNT, &my_putchar);
			*pos = 0;
		}
	}
	return (1);
}

int 	key_alt_down(int *pos, char *line)
{
	int len_prompt = (int)ft_strlen(stock_data(NULL)->prompt) + 3;
	int cols = (int)(stock_data(NULL)->winsize).col;

	if (len_prompt + (int)ft_strlen(line) > cols)
	{
		tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
		ft_putstr(line + *pos);
		int decalage_left;
		
		if ((int)ft_strlen((line + *pos)) > cols)
		{
			decalage_left = ft_strlen((line + *pos)) - cols;
			*pos += cols;
			tputs(tgoto(tgetstr("LE", NULL), 1, decalage_left), AFFCNT, &my_putchar);
		}
		else
		{
			decalage_left = ft_strlen((line + *pos));
			*pos += decalage_left; 
		}
	}
	return (1);
}

int 	key_alt_right(int *pos, char *line) // A CHANGER FIN DE CHAQUE MOT ET PAS DEBUT MOT SUIVANT 
{
	char	*ptr;
	int		state;

	state = 0;
	if (*pos < 0 || !*(line + *pos))
		return (1);
	ptr = line + *pos + 1;
	while (*ptr)
	{
		if (*ptr != ' ' && *ptr != '\t' && *ptr != '\v')
			state = 1;
		else if (state && (*ptr == ' ' || *ptr == '\t' || *ptr == '\v'))
		{
			tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
			ft_putstr(line + *pos);
			tputs(tgoto(tgetstr("LE", NULL), 1, ft_strlen(line + *pos) - ((ptr - 1) - (line + *pos))), AFFCNT, &my_putchar);
			*pos += (ptr - 1) - (line + *pos);
			return (1);
		}
		ptr++;
	}
	tputs(tgetstr("cd", NULL), AFFCNT, &my_putchar);
	ft_putstr(line + *pos);
	*pos += ptr - (line + *pos);
	return (1);
}

int 	key_alt_left(int *pos, char *line)
{
	char *ptr;
	int state;

	state = 0;
	if (!*pos)
		return (1);
	ptr = line + *pos - 1;
	while (ptr != line)
	{	
		if (*ptr != ' ' && *ptr != '\t' && *ptr != '\v')
			state = 1;
		else if (state && (*ptr == ' ' || *ptr == '\t' || *ptr == '\v'))
		{
			tputs(tgoto(tgetstr("LE", NULL), 1, (line + *pos) - ptr - 1), AFFCNT, &my_putchar);
			*pos -= (line + *pos) - ptr - 1;
			return (1);
		}
		ptr--;
	}
	tputs(tgoto(tgetstr("LE", NULL), 1, (line + *pos) - ptr), AFFCNT, &my_putchar);
	*pos -= (line + *pos) - ptr;
	return (1);
}