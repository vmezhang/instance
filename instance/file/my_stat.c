/*
 * =====================================================================================
 *
 *       Filename:  my_stat.c
 *
 *    Description:  获取文件属性
 *
 *        Version:  1.0
 *        Created:  2013年12月02日 21时32分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhangrui, v.mezhang@gmail.com
 *        Company:  Class 1107 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct stat buf;

	// 检查参数个数
	if (argc != 2) {
		printf("Usage:my_stat <filename>\n");
		exit(0);
	}
	// 获取文件属性
	if (stat(argv[1], &buf) == -1) {
		perror("stat:");
		exit(1);
	}

	// 打印文件属性
	printf("devic is:%d\n", buf.st_dev);
	printf("inode is:%d\n", buf.st_ino);
	printf("mode is:%o\n", buf.st_mode);
	printf("number of hard links is:%d\n", buf.st_nlink);
	printf("user ID of owner is:%d\n", buf.st_uid);
	printf("group Id of owner is:%d\n", buf.st_gid);
	printf("devic type (if inode device) is:%d\n", buf.st_rdev);

	printf("total size, in byte is:%d\n", buf.st_size);
	printf("blocksize for filesystem I/O is:%d\n", buf.st_blksize);
	printf("number of blocks allocated is:%d\n", buf.st_blocks);
	
	printf("time of last access is:%s\n", ctime(&buf.st_atime));
	printf("time of last modification is:%s\n", ctime(&buf.st_mtime));
	printf("time of last change is:%s\n", ctime(&buf.st_ctime));
	
	return 0;
}
