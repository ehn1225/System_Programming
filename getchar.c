#include <stdio.h>
#include <errno.h>

int main()
{
	FILE *fp;
	int c;

	if((fp = fopen("result", "r")) == NULL)
		perror("fopen:");
	c=getchar();
	printf("%c\n", c);
}
