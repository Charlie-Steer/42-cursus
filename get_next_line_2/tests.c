#include "get_next_line.h"
#include <fcntl.h>

char *text_file = "./gnlTester/files/multiple_line_with_nl";

int test_gnl()
{
	const char *file_to_read = text_file;

	int textfile_fd = open(file_to_read, O_RDONLY);
	if (textfile_fd == -1)
		return (-1);

	char *line = get_next_line(textfile_fd);
	printf("%s\n", line);
	free(line);
	return (0);
}

int test_gnl_for_iters(int n_iters)
{
	const char *file_to_read = text_file;

	int textfile_fd = open(file_to_read, O_RDONLY);
	if (textfile_fd == -1)
		return (-1);

	int i;
	while (i < n_iters)
	{
		char *line = get_next_line(textfile_fd);
		printf("%s", line);
		free(line);
		printf("---\n");
		i++;
	}
	close(textfile_fd);
	return (0);
}

void test_gnl_stdin(int n)
{
	int i = 0;
	while (i < n)
	{
		char *line = get_next_line(1);
		printf("%s", line);
		i++;
	}
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
	test_gnl_for_iters(20);

	// test_gnl();
	// test_gnl_stdin(5);
	// test_strlen("hello world?");
	return (0);
}
