/*�����ַ���*/
#include<stdio.h>
#include<stdlib.h>//����system("pause")��д�����ʱ��ǵ�ɾ��
#include<string.h>
int main()
{
	char str[100][101];
	int i=0,j=0,len=0,index[100],size=0;//len�����洢��ַ����ĳ��ȣ�index[100]�����洢������ַ�����λ�ã�j��ʾ��ַ����ĸ���-1��size��ʾ�ַ����ĸ���
	do//��ֹ�û�����100�����ַ�
	{
		scanf("%d",&size);//���û������ַ�������
		if(size>100)
			puts("\ntoo long,please enter a smaller size");//����û�������100�������ַ�����������������
	}while(size>100);
	for(i=0;i<=size;i++)
	{
		gets(str[i]);
		if((int)strlen(str[i])>len)//����и�����ַ���
		{
			len=strlen(str[i]);//����󳤶ȱ�����len��
			j=0;//���Ұ�j����
			index[j]=i;//�ѵ�ǰ�ַ����ı��i���index[j]
		}
		else if((int)strlen(str[i])==len)//����ҵ�����������ַ���
		{
			j++;
			index[j]=i;	//�򽫵�ǰ�ַ����ı��i���index����һ��λ��
		}
	}
	printf("The largest length is %d\nThe longest string(s) are:\n",len);
	for(i=0;i<=j;i++)
		puts(str[index[i]]);//���������ַ���
	system("pause");//����д�����ʱ��ǵ�ɾ��
	return 0;
}
