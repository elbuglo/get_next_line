#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
    char 	*line;
    int 	*fds;
    int 	i;
    int 	files_open;
    
    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", av[0]);
        return (1);
    }

    fds = malloc(sizeof(int) * (ac - 1));
    if (!fds)
        return (1);

    for (i = 0; i < ac - 1; i++)
    {
        fds[i] = open(av[i + 1], O_RDONLY);
        if (fds[i] == -1)
	        fprintf(stderr, "can't open : %s\n", av[i + 1]);
    }

    files_open = ac - 1;
    while (files_open > 0)
    {
        files_open = ac - 1;
        for (i = 0; i < ac - 1; i++)
        {
            if (fds[i] != -1)
            {
                line = get_next_line(fds[i]);
                if (line)
                {
                    printf("\n");
                    printf("Fd [%d]: %s", fds[i], line);
                    free(line);
                }
                else
                {
                    close(fds[i]);
                    fds[i] = -1;
                    files_open--;
                }
            }
            else
                files_open--;
        }
    }
    free(fds);
    return (0);
}
