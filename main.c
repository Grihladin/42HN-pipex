/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:08:08 by mratke            #+#    #+#             */
/*   Updated: 2024/11/22 23:11:15 by mratke           ###   ########.fr       */
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

char	*get_command_path(char **path, char *cmd)
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
	parametrs = malloc(j * sizeof(char *));
	cmd_prop.command_path = get_command_path(path, splited_cmd[0]);
	i = 0;
	j = 1;
	while (splited_cmd[j] != NULL)
	{
		parametrs[i] = splited_cmd[j];
		i++;
		j++;
	}
	parametrs[i] = NULL;
	cmd_prop.command_paramets = parametrs;
	return (cmd_prop);
}

int	main(int argc, char **argv, char **env)
{
	int				i;
	int				j;
	t_command_prop	cmd1;
	char			**e;
	char			**path;

	e = env;
	j = argc;
	e = argv;
	path = get_path(env);
	cmd1 = parse_cmd(path, "ipconfig -l rkqwrhjkqwerr rqr hq ejrw");
	ft_printf("%s\n\n", cmd1.command_path);
	i = 0;
	while (cmd1.command_paramets[i] != NULL)
	{
		ft_printf("%s\n", cmd1.command_paramets[i]);
		i++;
	}
}
