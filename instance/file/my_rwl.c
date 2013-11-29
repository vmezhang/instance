/*
 * =====================================================================================
 *
 *       Filename:  my_rwl.c
 *
 *    Description:  文件读写指针的移动操作过程 最后可使用od -c 来察看文件间隔
 *
 *        Version:  1.0
 *        Created:  2013年11月29日 09时53分37秒
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
#include <errno.h>
#include <string.h>

// 自定义错误处理函数
void my_err(const char *err_string, int line);

// 自定义的都数据函数
int my_read(int fd);

int main(int argc, char *argv[])
{
	int fd;
	char write_buf[32] = "Hello World!";

	// 在当前目录下创建文件example_rwl.c
	// if ((fd = creat("example_rwl.c", S_IRWXU)) == -1) {
	if ((fd = open("example_rwl.c", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU)) == -1) {
		my_err("open", __LINE__);
	} else {
		printf("create file success\n");
	}

	// 写数据
	if (write(fd, write_buf, strlen(write_buf)) != strlen(write_buf)) {
		my_err("write", __LINE__);
	}
	my_read(fd);
	
	// 演示文件间隔
	printf("/*------------------------------*/\n");
	if (lseek(fd, 10, SEEK_END) == -1) {
		my_err("lseek", __LINE__);
	}
	if (write(fd, write_buf, strlen(write_buf)) != strlen(write_buf)) {
		my_err("write", __LINE__);
	}
	my_read(fd);

	close(fd);
	return 0;
}

void my_err(const char *err_string, int line)
{
	fprintf(stderr, "line:%d ", line);
	perror(err_string);
	exit(1);
}

int my_read(int fd)
{
	int len;
	int ret;
	int i;
	char read_buf[64];

	// 获取文件长度并保持文件读写指针在开始处
	if (lseek(fd, 0, SEEK_END) == -1) {
		my_err("lseek", __LINE__);
	}
	if ((len = lseek(fd, 0, SEEK_CUR)) == -1) {
		my_err("lseek", __LINE__);
	}
	if (lseek(fd, 0, SEEK_SET) == -1) {
		my_err("lseek", __LINE__);
	}

	printf("len:%d\n", len);
	// 读数据
	if ((ret = read(fd, read_buf, len)) < 0) {
		my_err("read", __LINE__);
	}

	// 打印数据
	for (i = 0; i < len; i++) {
		printf("%c", read_buf[i]);
	}
	printf("\n");

	return ret;
}
