#include <stdio.h>
#include <errno.h>

int main()
{
	FILE *fp;
	int c;

	if((fp = fopen("result", "r")) == NULL)
		perror("fopen:");

	while(1){
		printf("%d %c %d\n",ftell(fp), fgetc(fp),  ftell(fp));
		if(feof(fp)){
			printf("end\n");
			fseek(fp, 0, SEEK_SET);
		}
	}
	printf("%d", fileno(fp));

}
