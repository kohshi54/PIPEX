#include "pipex.h"

void	execute_first(t_cmd_node *cur, int new_pipe[2])
{
	extern char **environ;

	close(new_pipe[READ]);
	dup2(new_pipe[WRITE], STDOUT_FILENO);
	close(new_pipe[WRITE]);
	execute_command(cur);
}

void	execute_last(t_cmd_node *cur, int old_read_end)
{
	extern char **environ;

	dup2(old_read_end, STDIN_FILENO);
	close(old_read_end);
	execute_command(cur);
}

void	execute_middle(t_cmd_node *cur, int new_pipe[2], int old_read_end)
{
	extern char **environ;

	close(new_pipe[READ]);
	dup2(old_read_end, STDIN_FILENO);
	close(old_read_end);
	dup2(new_pipe[WRITE], STDOUT_FILENO);
	close(new_pipe[WRITE]);
	execute_command(cur);
}

size_t get_node_count(t_cmd_node **cur)
{
	size_t i;

	i = 0;
	while (*cur)
	{
		cur++;
		i++;
	}
	return (i);
}

void execute_exit(t_cmd_node **cur)
{
	while (*cur)
	{
		printf("cur->str; %s\n", (*cur)->str);
		if (ft_strncmp((*cur)->str, "exit", 4) == 0)
			exit(0);
		cur++;
	}
}

int pipex(t_cmd_node **cur)
{
	int new_pipe[2];
	pid_t pid;
	int status;
	size_t cmdnum;
	int old_read_end;
	size_t	i;

	execute_exit(cur);
	i = 0;
	cmdnum = get_node_count(cur);
	ft_printf("cmdnum: %d\n", cmdnum);
	while (i < cmdnum)
	{
		if (i != cmdnum - 1)
			pipe(new_pipe);
		pid = fork();
		if (pid == 0)
		{
			if (i == 0)
				execute_first(cur[i], new_pipe);
			else if (i == cmdnum - 1)
				execute_last(cur[i], old_read_end);
			else
				execute_middle(cur[i], new_pipe, old_read_end);
		}
		if (i != 0)
			close(old_read_end);
		old_read_end = new_pipe[READ];
		close(new_pipe[WRITE]);
		// waitpid(pid, &status, 0);
		i++;
	}
	while (cmdnum-- > 0)
	{
		wait(&status);
		// waitpid(pid, &status, 0);
	}
	// ft_printf("success\n");
	return (0);
}



#include "fcntl.h"
int main(int argc, char *argv[])
{
	(void)argv;
	if (argc < 2)
	{
		printf("too few argumants\n");
		return (0);
	}
	t_cmd_node **arr = malloc(sizeof(t_cmd_node *) * 3);
	t_cmd_node *argone = malloc(sizeof(t_cmd_node));
	argone->kind = 1;
	argone->str = ft_strdup("ls");
	argone->next = NULL;
	t_cmd_node *argthree = malloc(sizeof(t_cmd_node));
	t_cmd_node *argtwo = malloc(sizeof(t_cmd_node));
	argtwo->kind = 0;
	argtwo->str = ft_strdup("grep");
	argtwo->next = argthree;
	argthree->kind = 0;
	argthree->str = ft_strdup("a");
	argthree->next = NULL;
	arr[0] = argone;
	arr[1] = argtwo;
	arr[2] = NULL;
	pipex(arr);
	ft_printf("returned to main\n");
	return (0);
}

/*
__attribute__((destructor))
static void destructor(void){
    system("leaks -q a.out");
}
*/