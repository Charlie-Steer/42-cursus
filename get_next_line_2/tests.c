#include "get_next_line.h"
#include <fcntl.h>

int test_gnl()
{
	const char *file_to_read = "text1";

	int textfile_fd = open(file_to_read, O_RDONLY);
	if (textfile_fd == -1)
		return (-1);

	char *line = get_next_line(textfile_fd);
	printf("%s\n", line);
	return (0);
}

void test_strlen(char *s)
{
	int len = ft_strlen(s);

	printf("str_len == %d\n", len);
}

void test_bzero()
{
	;
}

int main(void)
{
	test_gnl();
	// test_strlen("hello world?");
	return (0);
}
