#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

void test1(int iters)
{
	int fd1 = open("f1", O_RDONLY);
	int fd2 = open("f2", O_RDONLY);
	int fd3 = open("f3", O_RDONLY);
	
	int i = 0;
	while (i < iters)
	{
		char *l1 = get_next_line(fd1);
		char *l2 = get_next_line(fd2);
		char *l3 = get_next_line(fd3);
		
		printf("%s", l1);
		printf("%s", l2);
		printf("%s", l3);
		i++;
	}
} 

int main(void)
{
	test1(10);
	
	return (0);
}
