#include <stdio.h>
#include <stdlib.h>

void doubt(int * i){
	int a;//��������������Ҳ�ֹһ������program stopped at 0x401a6a it stopped with signal SIGSEGV, segmentation fault  
	a=2486;//�����Ҫ�������У��͵� 
	*i=257;//��i�����ʱ������дint *i=NULL;i=(int*)malloc(sizeof(int))....free(i) 
	*i=a;//����е���֣����������û�����⣬ 
}//���Ǻ����ǳ�һ��ĳ����������ͻ�������ص����� 
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