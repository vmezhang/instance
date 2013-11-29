/*
 * =====================================================================================
 *
 *       Filename:  fcntl_access.c
 *
 *    Description:  设置与获取文件打开方式
 *
 *        Version:  1.0
 *        Created:  2013年11月29日 21时04分06秒
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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// 自定义错误处理函数
void my_err(const char *err_string, int line);

int main(int argc, char *argv[])
{
	int ret;
	int access_mode;
	int fd;

	if ((fd = open("example_fc_acc", O_CREAT | O_TRUNC | O_RDWR, S_IRWXU)) == -1) {
		my_err("open", __LINE__);
	}

	// 设置文件打开方式
	// 以追加的方式写入文件后边
	if ((ret = fcntl(fd, F_SETFL, O_APPEND)) < 0) {
		my_err("fcntl", __LINE__);
	}

	// 获取文件打开方式
	if ((ret = fcntl(fd, F_GETFL, 0)) < 0) {
		my_err("fcntl", __LINE__);
	}
	
	// 输出文件打开方式
	access_mode = ret & O_ACCMODE;
	if (access_mode == O_RDONLY) {
		printf("example_fc_acc access mode: read only");
	} else if (access_mode == O_WRONLY) {
		printf("example_fc_acc access mode: write only");
	} else if (access_mode == O_RDWR) {
		printf("example_fc_acc access mode: read + write");
	}

	if (ret & O_APPEND) {
		printf(", append");
	}
	if (ret & O_NONBLOCK) {
		printf(", nonblock");
	}
	if (ret & O_SYNC) {
		printf(", sync");
	}
	printf("\n");
	
	return 0;
}

void my_err(const char *err_string, int line)
{
	fprintf(stderr, "line: %d", line);
	perror(err_string);
	exit(1);
}
