/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 17:09:14 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/19 15:40:44 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void 	remove_expension(char **ptr_begin, char *ptr_end)
{
	char *ptr;

	if (!ptr_begin || !*ptr_begin || !ptr_end)
		return ;
	ptr = *ptr_begin;
	while (*ptr_end)
	{
		**ptr_begin = *ptr_end;
		(*ptr_begin)++;
		ptr_end++;
	}
	//a voir pour ajouter un etat
	**ptr_begin = 0;
	printf("DEBUG | avnt ptr:%p\n", *ptr_begin);
	*ptr_begin = ptr;
	printf("DEBUG | apres ptr:%p\n", *ptr_begin);
	printf("DEBUG | ptr:%s\n", *ptr_begin);
}
static void		do_param_expension(char **value, char **ptr, t_params *params)
{
	printf("DEBUG | BEGIN do_variable_expension\n");
	char	*val;
	char	*ptr_end;
	char	c;

	if (!value || !*value || !ptr || !*ptr)
		return ;
	ptr_end = (*ptr) + 1;
	while (*ptr_end && ft_isalnum(*ptr_end))
	{
		ptr_end++;
	}
	c = *ptr_end;
	*ptr_end = 0;
	//LANCER RECHERCHE DANS LIST VAR (ENV + VAR)
	// si OK realloc
	// sinon suppression charactere expension
	printf("expension variable:%s\t%s\n", *ptr, (*ptr + 1));
	if (!(val = get_param(params->environment, (*ptr + 1))))
	{
		printf("no found in environment:%s\n", val);
		if (!(val = get_param(params->temporary, (*ptr + 1))))
		{
			printf("no found in temporary:%s\n", val);
			*ptr_end = c;
			remove_expension(ptr, ptr_end);
		}
	}
	if (val)
	{
		printf("found in environment go add param in value.\n");
		char *temp;
		int 	prev_len;
		//int 	next_len;

		prev_len = (*ptr) - *value;
		*ptr_end = c;
		if (!(temp = ft_strnew(prev_len + ft_strlen(val)
			+ (ft_strlen(ptr_end + 1)))))
		{
			//(*ptr)++;
			return ;
		}
		ft_strncpy(temp, *value, *ptr - *value);
		printf("a realloc:%s\t%ld\n", temp, *ptr - *value);
		ft_strcat(temp, val);
		printf("a realloc:%s\n", temp);
		ft_strcat(temp, ptr_end);
		free(*value);
		*value = temp;
		*ptr = temp + prev_len + ft_strlen(val);
		//(*ptr)++;
		printf("a realloc:%s\t%lu\n", val, prev_len + ft_strlen(val));
		printf("a realloc:%s\n", temp);
	}
}

void		param_expension(char **value, t_params *params)
{
	char *ptr;
	int		state;

	if (!value || !*value)
		return ;
	ptr = *value;
	state = 0;
	while (*ptr)
	{
		printf("in while char:%c\t%d\t%p\t%d\n", *ptr, *ptr, ptr, state);
		if (*ptr == '\\')
		{
			ptr++;
			//ptr += 2;
			//printf("cas:\\ ptr++\n");
		}
		else if (state != -2 && *ptr == 34)
		{
			state = (state == -1) ? 1 : -1;
			ptr++;
			printf("changement state:%d\n", state);
		}
		else if (state != -1 && *ptr == 39)
		{
			state = (state == -2) ? 1 : -2;
			ptr++;
			printf("changement state:%d\n", state);
		}
		else if (*ptr == '$' && state != -2)
		{
			printf("DEBUG | ptr:%p\n", ptr);
			if (*(ptr + 1) > 47 && *(ptr + 1) < 127)
			{
				printf("GO EXPENSION\n");
				do_param_expension(value, &ptr, params);
				state = 1;
			}
			ptr++;
		}
		//else //(*ptr)
		++ptr;
	}
}
