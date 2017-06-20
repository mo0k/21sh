/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 11:01:20 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/19 13:43:05 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static char 	*get_prefix_tilde(char *begin, char *addr_slash)
{
	if (!begin || !addr_slash || begin == addr_slash)
		return (NULL);
	*addr_slash = 0;
	return (begin);
}

static char 	*get_addr_slash(char *str)
{
	if (!str)
		return (NULL);
	while (*str && *str != '/')
		str++;
	return (str);
}
static int 		do_tilde_expension(char **value, char *tilde_str, char *addr_slash)
{
	char 	*new;
	if (!value || !*value || !tilde_str)
		return (0);
	if (!(new = ft_strjoin(tilde_str, addr_slash)))
		return (0);
	free(*value);
	*value = new;
	/*if (!(new = ft_strnew(ft_strlen(tilde_str) + ft_strlen(addr_slash))))
		return (0);
	ft_strcpy(new, tilde_str);
	*/
	return (1);
}

void		tilde_expension(char **value, t_params *params)
{
	printf("DEBUG | BEGIN tilde_expension\n");
	char homepath[150];
	char *addr_slash;
	char c;
	char *prefix;

	if (!value || !*value)
	{
		printf("1 return\n");
		return ;
	}
	if (**value == '~')
	{
		printf("DEBUG | **value == '$'\n");
		addr_slash = get_addr_slash(*value + 1);
		c = *addr_slash;
		prefix = get_prefix_tilde(*value + 1, addr_slash);
		if (!prefix)
		{
			printf("go getenv HOME\n");
			printf("%s\n", get_param(params->environment, "HOME"));
			*addr_slash = c;
			do_tilde_expension(value, get_param(params->environment, "HOME"), addr_slash);
		}
		else
		{
			ft_strcpy(homepath, "/Users/");
			ft_strncat(homepath, prefix, 144);
			*addr_slash = c;
			printf("DEBUG | homepath == '%s'\n", homepath);
			if ((access(homepath, F_OK) == -1))
			{
				printf("2 return\n");
				return;
			}
			else
			{
				printf("devollepement tilde\n");
				do_tilde_expension(value, homepath, addr_slash);
			}
		}
		
	}
	printf("DEBUG | END tilde_expension\n");
}
