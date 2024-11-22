/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:03:23 by mratke            #+#    #+#             */
/*   Updated: 2024/11/22 16:21:47 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>     // errno (used with strerror and perror)
#include <fcntl.h>     // open (flags like O_RDONLY, O_WRONLY, etc.)
#include <stdio.h>     // perror
#include <stdlib.h>    // malloc, free, exit
#include <string.h>    // strerror
#include <sys/types.h> // waitpid (POSIX types like pid_t)
#include <sys/wait.h>  // wait, waitpid
// open, close, read, write, access, dup, dup2, execve,
// fork, pipe, unlink, wait, waitpid
#include "ft_printf/ft_printf.h"
#include <unistd.h>
