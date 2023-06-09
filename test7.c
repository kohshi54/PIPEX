#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "../LIBFT.v2/libft.h"
#include "../LIBFT.v2/ft_split.c"
#include "../LIBFT.v2/ft_strlcpy.c"
#include "../LIBFT.v2/ft_strlen.c"
#include "../LIBFT.v2/ft_strncmp.c"
#include "../LIBFT.v2/ft_strjoin.c"

#define READ 0
#define WRITE 1

char *skip_first_five(char **path)
{
	size_t i;

	i = 5;
	while (i--)
		(*path)++;
	return (*path);
}

char *get_path(char **environ)
{
	while (*environ)
	{
		if (ft_strncmp(*environ, "PATH=", 5) == 0)
		{
			skip_first_five(environ);
			return (*environ);
		}
		environ++;
	}
	return ("not found");
}

char *search_command_path(char *command, char **environ)
{
	char *path;
	char **path_array;
	char *command_path;

	path = get_path(environ);
	path_array = ft_split(path, ':');
	command = ft_strjoin("/", command);
	while (*path_array)
	{
		command_path = ft_strjoin(*path_array, command);
		if (access(command_path, X_OK) == 0)
		{
			return (command_path);
		}
		path_array++;
	}
	return ("not found");
}

void execute_command(char *cmdline, char **environ)
{
	char **cmd;
	char *path;

	cmd = ft_split(cmdline, ' ');
	path = search_command_path(cmd[0], environ);
	execve(path, cmd, environ);
}

int main(int argc, char *argv[])
{
	int new_pipe[2];
	pid_t pid;
	extern char **environ;
	int status;
	int cmdnum;
	int old_read_end;
	size_t i;

	if (argc < 3)
	{
		printf("too few arguments\n");
		return (0);
	}
	cmdnum = argc - 1;
	i = 1;
	while (cmdnum)
	{
		if (cmdnum != 1)
			pipe(new_pipe);
		pid = fork();
		if (pid == 0)
		{
			if (cmdnum == argc - 1)
			{
				close(new_pipe[READ]);
				dup2(new_pipe[WRITE], STDOUT_FILENO);
				close(new_pipe[WRITE]);
				execute_command(argv[i], environ);
			}
			else if (cmdnum == 1)
			{
				dup2(old_read_end, STDIN_FILENO);
				close(old_read_end);
				execute_command(argv[i], environ);
			}
			else
			{
				close(new_pipe[READ]);
				dup2(old_read_end, STDIN_FILENO);
				close(old_read_end);
				dup2(new_pipe[WRITE], STDOUT_FILENO);
				close(new_pipe[WRITE]);
				execute_command(argv[i], environ);
			}
		}
		if (cmdnum != argc - 1)
			close(old_read_end);
		old_read_end = new_pipe[READ];
		close(new_pipe[WRITE]);
		waitpid(pid, &status, 0);
		cmdnum--;
		i++;
	}
	printf("success\n");
	return (0);
}