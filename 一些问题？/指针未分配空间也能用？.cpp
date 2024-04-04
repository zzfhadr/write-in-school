#include <stdio.h>
#include <stdlib.h>

void doubt(int * i){
	int a;//在这个编译器上我不止一次遇到program stopped at 0x401a6a it stopped with signal SIGSEGV, segmentation fault  
	a=2486;//如果想要正常运行，就得 
	*i=257;//在i定义的时候，这样写int *i=NULL;i=(int*)malloc(sizeof(int))....free(i) 
	*i=a;//真的有点奇怪，明明这个就没有问题， 
}//但是好像是长一点的程序不这样做就会出现严重的问题 
int main(int argc, char *argv[])
{
	int*i;
	free(i);
	int a;
	a=3;
	*i=a;
	printf("%d\n",*i);
	doubt(i);
		printf("%d\n",*i);
	return 0;
}