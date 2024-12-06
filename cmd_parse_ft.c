/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:34:32 by mratke            #+#    #+#             */
/*   Updated: 2024/12/06 20:00:30 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_command_path(char **path, char *cmd)
{
	int		i;
	char	*path_to_cmd;
	char	*command;

	command = ft_strjoin("/", cmd);
	i = 0;
	while (path[i] != NULL)
	{
		path_to_cmd = ft_strjoin(path[i], command);
		if (path_to_cmd == NULL)
		{
			free(command);
			return (NULL);
		}
		if (access(path_to_cmd, F_OK) == 0)
		{
			free(command);
			return (path_to_cmd);
		}
		free(path_to_cmd);
		i++;
	}
	free(command);
	return (NULL);
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
	while (splited_cmd[i] != NULL)
	{
		parametrs[i] = ft_strdup(splited_cmd[i]);
		i++;
	}
	parametrs[i] = NULL;
	cmd_prop.command_paramets = parametrs;
	free_double_ptr(splited_cmd);
	return (cmd_prop);
}

t_variabels	fill_variabels(int argc, char **argv, char **env)
{
	t_variabels	result;

	result.argc = argc;
	result.env = env;
	result.path = get_path(env);
	result.infile = open(argv[1], O_RDONLY);
	result.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	result.cmd1 = parse_cmd(result.path, argv[2]);
	result.cmd2 = parse_cmd(result.path, argv[3]);
	return (result);
}
