#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
#define CHAR_BUF_SIZE 100
	char buf[CHAR_BUF_SIZE];
	int str_len = strlen(argv[1]);
	int fp;
	int ret;

	assert(str_len < CHAR_BUF_SIZE);

	printf("Input size: %d\n", str_len);
	printf("Input string: %s\n", argv[1]);

	memset(buf, 0, CHAR_BUF_SIZE);

	fp = open("/dev/scull0", O_WRONLY);
	if (fp == -1) {
		printf("open scullo fail!!\n");
		return -1;
	}

	ret = write(fp, argv[1] , str_len);
	if (ret != str_len) {
		printf("write fail %d!!\n", ret);
		return -2;
	}

	fp = open("/dev/scull0", O_RDONLY);
	if (fp == -1) {
		printf("open scullo fail!!\n");
		return -1;
	}

	while(read(fp, buf, CHAR_BUF_SIZE))
		printf("Read from drv: %s\n", buf);

	return 0;
#undef CHAR_BUF_SIZE
}
