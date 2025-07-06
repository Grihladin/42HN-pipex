/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:36:18 by mratke            #+#    #+#             */
/*   Updated: 2024/12/06 19:40:17 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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

void	free_double_ptr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(t_variabels v)
{
	free(v.cmd1.command_path);
	free_double_ptr(v.cmd1.command_paramets);
	free(v.cmd2.command_path);
	free_double_ptr(v.cmd2.command_paramets);
	free_double_ptr(v.path);
}
