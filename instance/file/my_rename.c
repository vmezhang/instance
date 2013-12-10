/*
 * =====================================================================================
 *
 *       Filename:  my_rename.c
 *
 *    Description:  更改文件名
 *
 *        Version:  1.0
 *        Created:  2013年12月10日 20时56分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhangrui, v.mezhang@gmail.com
 *        Company:  Class 1107 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	// 检查参数的合法性
	if (argc < 3) {
		printf("my_rename <old file> <new file>\n");
		exit(0);
	}

	if (rename(argv[1], argv[2]) < 0) {
		perror("rename");
		exit(1);
	}
	return 0;
}


