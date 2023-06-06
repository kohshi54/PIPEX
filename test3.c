#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "../LIBFT.v2/libft.h"
#include "../LIBFT.v2/ft_split.c"
#include "../LIBFT.v2/ft_strlcpy.c"
#include "../LIBFT.v2/ft_strlen.c"
#include "../LIBFT.v2/ft_strncmp.c"
#include "../LIBFT.v2/ft_strjoin.c"

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
	return ("");
}

char *search_command_path(char **environ, char *command)
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
	return ("");
}

int main(void)
{
	extern char **environ;
	int pipefd[2];
	char *cmd1[] = {"ls", "-l", NULL};
	char *cmd2[] = {"wc", "-l", NULL};
	char *path;

	pipe(pipefd);
	pid_t pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		path = search_command_path(environ, cmd1[0]);
		execve(path, cmd1, environ);
	}

	int status;
	waitpid(pid, &status, 0);
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	path = search_command_path(environ, cmd2[0]);
	execve(path, cmd2, environ);

	return (0);
}