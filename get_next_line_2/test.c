#include <stdlib.h>
#include <stdio.h>

void modify_static(char* st)
{
	st[5] = 'e';
	st[6] = 's';
}

void modify_pointer_to_static(char** st)
{
	(*st)[5] = 'A';
	(*st)[6] = 'A';
}

void subroutineA()
{
	char *st;
	st = malloc(8);
	for (int i = 0; i < 8; i++){
		st[i] = "charlie\0"[i];
	}
	printf("before %s\n", st);
	modify_static(st);
	printf("after %s\n", st);
	printf("---\n");
	printf("before %s\n", st);
	modify_pointer_to_static(&st);
	printf("after %s\n", st);
}

int main(void)
{
	subroutineA();
	return (0);
}
