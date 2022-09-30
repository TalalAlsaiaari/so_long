/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 01:00:40 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 00:28:57 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/so_long.h"

static int	word_count(char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	split = (char **)malloc((word_count(s, c) + 1) * sizeof(char **));
	if (split == 0)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			split[k] = ft_substr(s, j, i - j);
			k++;
		}
	}
	split[k] = 0;
	return (split);
}
