#include "pipex.h"

void	execute_first(char *cmd, int new_pipe[2])
{
	extern char **environ;

	close(new_pipe[READ]);
	dup2(new_pipe[WRITE], STDOUT_FILENO);
	close(new_pipe[WRITE]);
	execute_command(cmd, environ);
}

void	execute_last(char *cmd, int old_read_end)
{
	extern char **environ;

	dup2(old_read_end, STDIN_FILENO);
	close(old_read_end);
	execute_command(cmd, environ);
}

void	execute_middle(char *cmd, int new_pipe[2], int old_read_end)
{
	extern char **environ;

	close(new_pipe[READ]);
	dup2(old_read_end, STDIN_FILENO);
	close(old_read_end);
	dup2(new_pipe[WRITE], STDOUT_FILENO);
	close(new_pipe[WRITE]);
	execute_command(cmd, environ);
}

void	validate_input(int argc)
{
	if (argc < 3)
	{
		ft_printf("too few arguments\n");
		exit(0);
	}
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

	validate_input(argc);
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
				execute_first(argv[i], new_pipe);
			else if (cmdnum == 1)
				execute_last(argv[i], old_read_end);
			else
				execute_middle(argv[i], new_pipe, old_read_end);
		}
		if (cmdnum != argc - 1)
			close(old_read_end);
		old_read_end = new_pipe[READ];
		close(new_pipe[WRITE]);
		waitpid(pid, &status, 0);
		cmdnum--;
		i++;
	}
	ft_printf("success\n");
	return (0);
}

/*
__attribute__((destructor))
static void destructor(void){
    system("leaks -q a.out");
}
*/