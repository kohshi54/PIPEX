#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "LIBFT/libft.h"
#include "LIBFT/ft_printf.h"

#define READ 0
#define WRITE 1

/* execute_command.c */
char *get_path_from_env(char **environ);
char *get_command_path(char *command, char **environ);
void execute_command(char *cmdline, char **environ);

#endif