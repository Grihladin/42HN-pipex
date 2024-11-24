/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:08:08 by mratke            #+#    #+#             */
/*   Updated: 2024/11/24 18:39:59 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int				j;
	t_command_prop	cmd1;
	t_command_prop	cmd2;
	char			**e;
	char			**path;
	pid_t			process_id_1;
	int				pipe_fd[2];
	int				file1_fd;

	// pid_t			process_id_2;
	j = argc;
	e = argv;
	path = get_path(env);
	cmd1 = parse_cmd(path, "ls");
	cmd2 = parse_cmd(path, "wc -l");
	file1_fd = open("file1", O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (pipe(pipe_fd) == -1)
	{
		perror("Pipe creathion error");
		exit(EXIT_FAILURE);
	}
	process_id_1 = fork();
	if (process_id_1 == -1)
	{
		perror("Child process 1 creathion failed");
		exit(EXIT_FAILURE);
	}
	else if (process_id_1 == 0)
	{
		dup2(file1_fd, STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(cmd1.command_path, cmd1.command_paramets, env);
		perror("Command executhion in child 1 failed");
		exit(EXIT_FAILURE);
	}
	// process_id_2 = fork();
	// if (process_id_2 == -1)
	// {
	// 	perror("Child process 2 creathion failed");
	// 	exit(EXIT_FAILURE);
	// }
	// else if (process_id_2 == 0)
	// {
	// 	dup2(pipe_fd[0], STDIN_FILENO);
	// 	dup2(file1_fd, STDOUT_FILENO);
	// 	close(pipe_fd[0]);
	// 	close(pipe_fd[1]);
	// 	close(file1_fd);
	// 	execve(cmd2.command_path, cmd2.command_paramets, env);
	// 	perror("Command executhion in child 2 failed");
	// 	exit(EXIT_FAILURE);
	// }
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	close(file1_fd);
	waitpid(process_id_1, NULL, 0);
	// waitpid(process_id_2, NULL, 0);
}
