#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char *str;

	printf("%p\n", str);
	str = malloc(14);
	printf("%p\n", str);
	memcpy(str, "hallo there!\n\0", 14);
	write(1, str, 13);
	free(str);
	write(1, str, 13);
	printf("\n");
	printf("%p\n", str);
	str = NULL;
	printf("%p\n", str);
	return (0);
}
