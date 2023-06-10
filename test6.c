#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define READ 0
#define WRITE 1

int main(void)
{
	int new_pipe[2];
	pid_t pid;
	char *cmd1[] = {"cat", "./infile", NULL};
	char *cmd2[] = {"grep", "a1", NULL};
	char *cmd3[] = {"wc", "-l", NULL};
	extern char **environ;
	int status;
	int cmdnum = 3;
	int old_read_end;

	while (cmdnum)
	{
		if (cmdnum != 1)
			pipe(new_pipe);
		pid = fork();
		if (pid == 0)
		{
			if (cmdnum == 3)
			{
				close(new_pipe[READ]);
				dup2(new_pipe[WRITE], STDOUT_FILENO);
				close(new_pipe[WRITE]);
				execve("/bin/cat", cmd1, environ);
			}
			else if (cmdnum == 1)
			{
				dup2(old_read_end, STDIN_FILENO);
				close(old_read_end);
				execve("/usr/bin/wc", cmd3, environ);
			}
			else
			{
				close(new_pipe[READ]);
				dup2(old_read_end, STDIN_FILENO);
				close(old_read_end);
				dup2(new_pipe[WRITE], STDOUT_FILENO);
				close(new_pipe[WRITE]);
				execve("/usr/bin/grep", cmd2, environ);
			}
		}
		if (cmdnum != 3)
			close(old_read_end);
		old_read_end = new_pipe[READ];
		close(new_pipe[WRITE]);
		waitpid(pid, &status, 0);
		cmdnum--;
	}
	printf("success\n");
	return (0);
}