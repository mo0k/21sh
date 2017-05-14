/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 09:47:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/30 15:56:34 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str3join(char const *s1, char const *s2, char const *s3)
{
	char	*ptr;
	int		len;

	ptr = NULL;
	if (!s1 || !s2 || !s3)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	if (!(ptr = ft_strnew(len)))
		return (NULL);
	ptr = ft_strcpy(ptr, s1);
	ptr = ft_strcat(ptr, s2);
	ptr = ft_strcat(ptr, s3);
	return (ptr);
}
