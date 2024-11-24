/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:34:32 by mratke            #+#    #+#             */
/*   Updated: 2024/11/24 16:41:22 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char	*path;
	char	**splited_path;

	path = env[2];
	splited_path = ft_split(path, ':');
	return (splited_path);
}

static char	*get_command_path(char **path, char *cmd)
{
	int		i;
	char	*path_to_cmd;

	cmd = ft_strjoin("/", cmd);
	i = 0;
	while (path[i] != NULL)
	{
		path_to_cmd = ft_strjoin(path[i], cmd);
		if (access(path_to_cmd, F_OK) == 0)
			return (path_to_cmd);
		path_to_cmd = free_and_return_empty(path_to_cmd);
		i++;
	}
	return (path_to_cmd);
}

t_command_prop	parse_cmd(char **path, char *cmd)
{
	t_command_prop	cmd_prop;
	char			**parametrs;
	char			**splited_cmd;
	int				j;
	int				i;

	j = 0;
	splited_cmd = ft_split(cmd, ' ');
	while (splited_cmd[j] != NULL)
		j++;
	parametrs = malloc((j + 1) * sizeof(char *));
	cmd_prop.command_path = get_command_path(path, splited_cmd[0]);
	i = 0;
	j = 0;
	while (splited_cmd[j] != NULL)
	{
		parametrs[i] = splited_cmd[j];
		i++;
		j++;
	}
	parametrs[i] = NULL;
	cmd_prop.command_paramets = parametrs;
	return (free(splited_cmd), cmd_prop);
}
