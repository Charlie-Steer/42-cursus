#include "get_next_line.h"
#include <fcntl.h>

static void test_read_01(void)
{
	int text_file_fd = open("text.txt", O_RDONLY);
	char *buf = malloc(BUF_SIZE);
	for (int i = 0; i < 40; i++)
	{
		read(text_file_fd, buf, BUF_SIZE);
		write(1, buf, BUF_SIZE);
	}
	free(buf);
}

static void string_null_test(void)
{
	char *s;

	s = NULL;
	printf("%p\n", s);
	if (s == NULL)
		printf("s is NULL\n");
	else
		printf("s is NOT NULL\n");
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	for (int i = 0; i < 3; i++)
		printf("%s", get_next_line(fd));
	return (0);
}
