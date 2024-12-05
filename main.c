#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int fd = open("sa.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL) // Parantezler eklendi.
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
}
