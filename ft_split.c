/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:52:13 by labia-fe          #+#    #+#             */
/*   Updated: 2024/12/19 06:09:30 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	ft_freeall(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	ft_nword(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			n++;
		i++;
	}
	return (n);
}

static char	*ft_getword(const char *s, char c)
{
	char	*buffer;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	buffer = malloc(sizeof(char) * (i + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * (ft_nword(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i] && j < ft_nword(s, c))
	{
		if (s[i] != c)
		{
			str[j] = ft_getword(s + i, c);
			if (!str[j])
				return (ft_freeall(str), NULL);
			i = i + strlen(str[j]);
			j++;
		}
		else
			i++;
	}
	str[j] = NULL;
	return (str);
}
