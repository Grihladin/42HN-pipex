/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:36:18 by mratke            #+#    #+#             */
/*   Updated: 2024/11/27 19:34:06 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_strncmp(const char *lhs, const char *rhs, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count && lhs[i] == rhs[i])
	{
		if (lhs[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	if (i == count)
	{
		return (0);
	}
	return ((unsigned char)lhs[i] - (unsigned char)rhs[i]);
}

char	**get_path(char **env)
{
	int		i;
	char	*path;
	char	**splited_path;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
			break ;
		}
		else
			path = NULL;
		i++;
	}
	if (path == NULL)
		path = DEFAULT_PATH;
	splited_path = ft_split(path, ':');
	return (splited_path);
}
