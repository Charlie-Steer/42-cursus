#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int n_chars = 6;
	char *s = malloc(n_chars);
	int i = 0;
	while (i < n_chars)
	{
		s[i] = "hello\0"[i];
		i++;
	}
	printf("%s\n", s);
	free(s);
	return (0);
}
