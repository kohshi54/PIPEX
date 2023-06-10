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
char *get_path_from_env();
char *get_command_path(char *command);
void execute_command(char *cmdline);

#endif