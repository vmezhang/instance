/*
 * =====================================================================================
 *
 *       Filename:  show_file.c
 *
 *    Description:  获取文件目录信息
 *
 *        Version:  1.0
 *        Created:  2013年12月10日 21时53分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhangrui, v.mezhang@gmail.com
 *        Company:  Class 1107 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

// 获取目录信息
int my_readir(const char *path);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("listfile <target path>\n");
		exit(1);
	}

	if (my_readir(argv[1]) < 0) {
		exit(1);
	}

	return 0;
}

int my_readir(const char *path)
{
	DIR *dir;
	struct dirent *ptr;

	if ((dir = opendir(path)) == NULL) {
		perror("opendir");
		return -1;
	}
	while ((ptr = readdir(dir)) != NULL) {
		printf("file name:%s\n", ptr->d_name);
	}
	closedir(dir);

	return 0;
}


