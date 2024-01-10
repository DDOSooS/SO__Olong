
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

char    **ft_gen_map(fd)
{
    char	*buffer;
	char	*str;
	int		b_read;

	str = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	b_read = read(fd, buffer, BUFFER_SIZE);
	while (b_read > 0)
	{
		str = ft_strcat(str, buffer);
		b_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (b_read == -1)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        perror("PLEAS TRY AGIAN! with one map with mbp type");
        return (0);
    }
    printf("%s",argv[1])
    return (1);
}