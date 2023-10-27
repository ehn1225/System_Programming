#include <stdio.h>
#include <errno.h>

int main()
{
	FILE *fp;
	int c;

	if((fp = fopen("result", "r")) == NULL)
		perror("fopen:");

	while(1){
		c = fgetc(fp);
		printf("%c", c);
		if(feof(fp)){
			printf("end\n");
			break;
		}
	}
}
