/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:03:23 by mratke            #+#    #+#             */
/*   Updated: 2024/12/06 19:37:53 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>     // errno (used with strerror and perror)
# include <fcntl.h>     // open (flags like O_RDONLY, O_WRONLY, etc.)
# include <stdio.h>     // perror
# include <stdlib.h>    // malloc, free, exit
# include <string.h>    // strerror
# include <sys/types.h> // waitpid (POSIX types like pid_t)
# include <sys/wait.h>  // wait, waitpid
// open, close, read, write, access, dup, dup2, execve,
// fork, pipe, unlink, wait, waitpid
# include "../libft/inc/libft.h"
# include "../ft_printf/inc/ft_printf.h"
# include <unistd.h>

# define DEFAULT_PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"

typedef struct s_command_prop
{
	char			*command_path;
	char			**command_paramets;
}					t_command_prop;

typedef struct s_variables
{
	int				argc;
	int				infile;
	int				outfile;
	char			**path;
	char			**env;
	t_command_prop	cmd1;
	t_command_prop	cmd2;
	pid_t			pid_1;
	pid_t			pid_2;
}					t_variabels;

t_command_prop		parse_cmd(char **path, char *cmd);
char				**get_path(char **env);
t_variabels			fill_variabels(int argc, char **argv, char **env);
void				free_double_ptr(char **arr);
void				free_all(t_variabels v);
#endif
