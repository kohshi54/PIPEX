#include <stdio.h>

int	main(int argc, char *argv[])
{
	size_t	i;

	if (argc < 2)
		return (0);
	i = 0;
	while (argv[i])
	{
		printf("argv[%zu]: %s\n", i, argv[i]);
		i++;
	}
	return (0);
}