/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 00:58:10 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 00:29:09 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../include/so_long.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	if (start < ft_strlen(s))
	{
		while (len--)
		{
			substr[i++] = s[start++];
		}
	}
	substr[i] = '\0';
	return (substr);
}
