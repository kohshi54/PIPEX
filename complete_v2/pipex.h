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

typedef struct s_cmd_node
{
	int					kind;
	char				*str;
	struct s_cmd_node	*next;
}	t_cmd_node;

/* execute_command.c */
char *get_path_from_env();
char *get_command_path(char *command);
void execute_command(t_cmd_node *cmdline);

#endif