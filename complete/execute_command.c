#include "pipex.h"

char *get_path_from_env()
{
	extern char **environ;

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

char *get_command_path(char *command)
{
	char *path;
	char **path_array;
	char *command_path;
	extern char **environ;

	path = get_path_from_env();
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

void execute_command(char *cmdline)
{
	char **cmd;
	char *path;
	extern char **environ;

	cmd = ft_split(cmdline, ' ');
	path = get_command_path(cmd[0]);
	execve(path, cmd, environ);
}