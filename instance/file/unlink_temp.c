/*
 * =====================================================================================
 *
 *       Filename:  ulink_temp.c
 *
 *    Description:  利用unlink函数删除文件
 *
 *        Version:  1.0
 *        Created:  2013年12月10日 21时03分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhangrui, v.mezhang@gmail.com
 *        Company:  Class 1107 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// 自定义错误处理函数
void my_err(const char *err_string, int line);

int main(int argc, char *argv[])
{
	int fd;
	char buf[32];

	if ((fd = open("temp", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU)) < 0) {
		my_err("open", __LINE__);
	}
	if (unlink("temp") < 0) {
		my_err("unlink", __LINE__);
	}
	printf("file unlinked\n");

	if (write(fd, "temp", 5) < 0) {
		my_err("write", __LINE__);
	}
	if ((lseek(fd, 0, SEEK_SET)) == -1) {
		my_err("lseek", __LINE__);
	}
	if (read(fd, buf, 5) < 0) {
		my_err("read", __LINE__);
	}
	printf("%s\n", buf);

	return 0;
}

void my_err(const char *err_string, int line) 
{
	fprintf(stderr, "line:%d", line);
	perror(err_string);
	exit(1);
}

