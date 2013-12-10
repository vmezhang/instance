/*
 * =====================================================================================
 *
 *       Filename:  my_cdvc.c
 *
 *    Description:  利用chdir编写的cd命令
 *
 *        Version:  1.0
 *        Created:  2013年12月10日 21时31分40秒
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
#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>

void my_err(const char *err_string, int line);
int my_cd(int a, char *b[]);

int main(int argc, char *argv[])
{
	char buf[PATH_MAX + 1];
	
	if (argc < 2) {
		printf("my_cd <tartget path>\n");
		exit(1);
	}

	if (chdir(argv[1]) < 0) {
		my_err("chdir", __LINE__);
	}
	if (getcwd(buf, 512) < 0) {
		my_err("getcwd", __LINE__);
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
