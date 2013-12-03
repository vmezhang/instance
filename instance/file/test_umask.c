/*
 * =====================================================================================
 *
 *       Filename:  test_umask.c
 *
 *    Description:  设置文件创建时的屏蔽字
 *
 *        Version:  1.0
 *        Created:  2013年12月03日 20时57分38秒
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
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	// 不屏蔽任何权限
	umask(0);
	if (creat("example_umask1.txt", S_IRWXU | S_IRWXG | S_IRWXO) < 0) {
		perror("creat");
		exit(1);
	}

	// 屏蔽其他用户的所有权限
	umask(S_IRWXO);
	if (creat("example_umask2.txt", S_IRWXU | S_IRWXG | S_IRWXO) < 0) {
		perror("creat");
		exit(1);
	}
	
	return 0;
}


