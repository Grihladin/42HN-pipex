/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:08:08 by mratke            #+#    #+#             */
/*   Updated: 2024/12/06 19:31:07 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_first(int *pipe_fd, t_variabels v)
{
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(v.infile, STDIN_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execve(v.cmd1.command_path, v.cmd1.command_paramets, v.env);
	perror("Command executhion in child 1 failed, %s does not exist");
	free_all(v);
	exit(EXIT_FAILURE);
}

void	execute_last(int *pipe_fd, t_variabels v)
{
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(v.outfile, STDOUT_FILENO);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	close(v.outfile);
	execve(v.cmd2.command_path, v.cmd2.command_paramets, v.env);
	perror("Command executhion in child 2 failed, %s does not exist");
	free_all(v);
	exit(EXIT_FAILURE);
}

void	exit_and_perror(char *messege)
{
	perror(messege);
	exit(EXIT_FAILURE);
}

void	close_fds(int *pipe_fd, int fd1, int fd2)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(fd1);
	close(fd2);
}

int	main(int argc, char **argv, char **env)
{
	t_variabels	v;
	int			pipe_fd[2];

	if (argc != 5)
		return (1);
	if (pipe(pipe_fd) == -1)
		exit_and_perror("Pipe fd creathion error");
	v = fill_variabels(argc, argv, env);
	v.pid_1 = fork();
	if (v.pid_1 == -1)
		exit_and_perror("Child process 1 fork failed");
	else if (v.pid_1 == 0)
		execute_first(pipe_fd, v);
	v.pid_2 = fork();
	if (v.pid_2 == -1)
		exit_and_perror("Child process 2 fork failed");
	else if (v.pid_2 == 0)
		execute_last(pipe_fd, v);
	close_fds(pipe_fd, v.infile, v.outfile);
	waitpid(v.pid_1, NULL, 0);
	waitpid(v.pid_2, NULL, 0);
	free_all(v);
	return (0);
}
