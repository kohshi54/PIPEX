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
#include <fcntl.h>
#include <string.h>
bool detect_redirect(char **cmd)
{
	while (cmd && *cmd)
	{
		if (strncmp(*cmd, "<", 1) == 0)
		{
			return (true);
		}
		cmd++;
	}
	return (false);
}

size_t count_node(t_cmd_node *cur)
{
	size_t	i;

	i = 0;
	while (cur)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

char **make_double_array(t_cmd_node *cur)
{
	char	**cmd;
	size_t	num;
	char	**head;

	num = count_node(cur);
	cmd = malloc(sizeof(char *) * (num + 1));
	head = cmd;
	while (cur)
	{
		*cmd = cur->str;
		cur = cur->next;
		cmd++;
	}
	*cmd = NULL;
	return (head);
}

void execute_command(t_cmd_node *cur)
{
	char **cmd;
	char *path;
	extern char **environ;

	// printf("%d\n", cur->kind);
	// cmd = ft_split(cur->str, ' ');
	cmd = make_double_array(cur);
	if (cur->kind == 1)
	{
		int fd = open("./ttt", O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	if (cur->kind == 2)
	{
		/* heredoc */
	}
	path = get_command_path(cmd[0]);
	execve(path, cmd, environ);
}