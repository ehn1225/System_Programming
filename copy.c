#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int fd1, fd2, n;
	char buf[1024];
	if (argc < 3) {
		fprintf(stderr, “Usage; %s src dest\n”, argv[0]);
		exit(1);
	}

	if ((fd1 = open(argv[1], O_RDONLY)) < 0) {
		perror(“Error:”);
		exit(1);
	}

	if ((fd2 = creat(argv[2], 0644)) < 0) {
		perror(“Error:”);
		exit(1);
	}

	while ((n = read(fd1, buf, 1024)) > 0)
		write(fd2, buf, n);

	close(fd1);
	close(fd2);
}
