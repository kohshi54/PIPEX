#include "pipex.h"

char *get_path_from_env(char **environ)
{
	while (*environ)
	{
		if (ft_strncmp(*environ, "PATH=", 5) == 0)
		{
			ft_strtrim(*environ, "PATH=");
			return (*environ);
		}
		environ++;
	}
	return ("not found");
}

char *get_command_path(char *command, char **environ)
{
	char *path;
	char **path_array;
	char *command_path;

	path = get_path_from_env(environ);
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
	path = get_command_path(cmd[0], environ);
	execve(path, cmd, environ);
}