#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float calcu(float sp, float si, int spsca, int sisca)//-db -g -h 6 45
{
	float a,b;
	float time;
	a=si;
	if(sisca==1)
	a=si*1024.0;	
	b=sp;
	if(spsca==0)
	b=sp/8.0;
	if(spsca==2)
	b=sp/1024.0;
	time=a/b;
	return time;
}
#define temp buffer[i]
#define tem1 buffer[i+1]
#define tem2 buffer[i+2]
void change(char *buffer, float *sp, float *si)//������getdata������buffer�е�speed��sizeֵ�ó��� 
{
	int j=-1,e=-1;
	int i=0,k=0,l=0;
	float sp1=0,si1=0;
	char task[13]={"\0"},tas1[13]={"\0"};
	for(i=0;i<50;i++)
	{
		if(temp!=' ')
		{		
			if(l==1){
				j++;
				task[j]=temp;	
				//printf("%cadsfadsf%d\n",temp,j);
			}			
			if(k==0)
			k++;
			if(k==2){
				if(temp=='\0')
				break;
				e++;
				tas1[e]=temp;
			}							
		}
		else if (l==0)
		l++;
		else if (k==1)//-xb -g -h 6 45
		l++,k++;//?
	}
	
	task[j+1]='\0';
	tas1[e+1]='\0';
	for(i=0;i<=j;i++)
	{
		if(task[i]=='.')
		{
			l=i;
			break;
		}
		else
		l=j+1;		
	}
	for(i=0;i<=j;i++){
		if(task[i]!='.'){
			if(i<l){
				if((l-i)>1)
				sp1+=(task[i]-'0')*pow(10.0,(float)(l-i-1));
				else if ((l-i)==1)
				sp1+=(task[i]-'0')*1.0;
			}
			else
			sp1+=(task[i]-'0')/pow(10.0,(float)(i-l));
		}
	}
	for(i=0;i<=e;i++)
	{
		if(tas1[i]=='.')
		{
			l=i;
			break;
		}
		else
		l=e+1;		
	}
	for(i=0;i<=e;i++){
		if(tas1[i]!='.'){
			if(i<l){
				if((l-i)>1)
				si1+=(tas1[i]-'0')*pow(10.0,(float)(l-i-1));	
				else if ((l-i)==1)
				si1+=(tas1[i]-'0')*1.0;
			}
			else
			si1+=(tas1[i]-'0')/pow(10.0,(float)(i-l));
		}
	}
	*sp=sp1,*si=si1;
}
int getdata(char * buffer, int *spsca, int *sisca, int *tisca)
{
	int i,k;
	k=0;

	for(i=0;i<50;i++)
	{
		if(temp=='-')
		k++;
		if(k==1)
		{
			if(tem1=='d'&&tem2=='b'){ 
				//printf("fuckk you");
				*spsca=1;
				temp=' ';
				tem1=' ';
				tem2=' '; 
			} 
			if(tem1=='x'&&tem2=='b'){	
				*spsca=0;
				temp=' ';
				tem1=' ';
				tem2=' ';
			}
			if(tem1=='k'&&tem2=='b')
			{
				*spsca=2;
				temp=' ';
				tem1=' ';
				tem2=' ';	
			}
		}//-db -g -h 6 45
		if(k==2)
		{
			if(tem1=='g'){ 
				*sisca=1;
				temp=' ';
				tem1=' ';
			} 
			if(tem1=='m'){ 
				*sisca=0;
				temp=' ';
				tem1=' ';
			} 
		}
		if(k==3)
		{
			if(tem1=='s'){
				*tisca=1;
			}
			if(tem1=='m'){
				*tisca=2;
			}
			if(tem1=='h'){
				*tisca=3;				
			}
			if(tem1=='d'){
				*tisca=4;
			}
			temp=' ';
			tem1=' ';//-xb -g -h 6 45
			k++;//���if���ִֻ��һ�� 
			break;
		}		
	}
	
	if(k<1||k>4)
	return 1;
	else
	return 0;	
}
void outter(float time, int spsca, int sisca, int tisca){
	float c;
	int i;
	int j,l;
	float b;
	float a;
	if(tisca==1){
		printf("Ԥ������ʱ��Ϊ��%f��\n",time);
	}
	if(tisca==2){
		c=time/60.0;
		i=(int)c;
		b=c-(float)i;
		b=b*60;
		printf("Ԥ������ʱ��Ϊ��%d��%f��\n",i,b);		
	}
	
	if(tisca==3){
		c=time/3600.0;
		i=(int)c;
		b=c-(float)i;
		b=b*60;
		j=(int)b;
		b=b-(float)j;
		b=b*60;
		printf("Ԥ������ʱ��Ϊ��%dСʱ%d��%f��\n",i,j,b);
		
	}
	if(tisca==4){
		c=time/86400.0;
		i=(int)c;
		b=c-(float)i;
		b=b*24;
		j=(int)b;
		b=b-(float)j;
		b=b*60;
		l=(int)b;
		b=b-(float)l;
		b=b*60;
		printf("Ԥ������ʱ��Ϊ��%d��%dСʱ%d��%f��\n",i,j,l,b);
	}
}
int main(int argc, char *argv[])
{
	char buffer[50]={"\0"};
	int *spsca=NULL; int *sisca=NULL; int *tisca=NULL;
	int state;
	float *sp=NULL,*si=NULL;
	float time;
	float sp1,si1;
	int spsc1,sisc1,tisc1;
	char i='1'; 
	int k=0;
	printf("-db -g -s ��ʾ�����ٶȵ�λMB/s,�����λΪ��\n -xb -s��ʾ�����ٶȵ�λMb/s,�ļ���С��λΪGB,���ʱ�䵥λΪ��\n�����ٶ����ֵ�λkB/s:kb,MB/s:db,Mb/s:xb ; �ļ���С���ֵ�λ��GB:g,MB:m ; ʱ�䵥λ����:s,��:m,Сʱ:h,��:d��\n�磺-db -g -h 6 45\n");
	while(1)
	{
		spsca=(int*)malloc(sizeof(int));//�������������е�ʱ������û�н�������� 
		sisca=(int*)malloc(sizeof(int));//�����ʱ����е��ԣ�����ִ�����ʾ���ڣ� 
		tisca=(int*)malloc(sizeof(int));// program stopped at 0x401a6a it stopped with signal SIGSEGV, segmentation fault 
		sp=(float*) malloc(sizeof(float));
		si=(float*) malloc(sizeof(float));
		i='1';
		printf(":"); 
		gets(buffer);
		//-db -g -h 6 45		
		state=getdata(buffer,spsca,sisca,tisca);
		change(buffer,sp,si);		
		sp1=*sp;
		si1=*si;		
		spsc1=*spsca;
		sisc1=*sisca;
		tisc1=*tisca;
		time=calcu(sp1,si1,spsc1 ,sisc1);
		outter(time,spsc1,sisc1,tisc1);//����Outter��outter����һЩû��д����ĺ���������ˡ�main��ǰ�沿��Ҳ�����޸��˴�Ű� 
		free(spsca);
		free(sisca);
		free(tisca);
		free(sp);
		free(si);
		printf("---����0�رմ��ڣ�(������ֻ������һ���ַ�)  :");
		scanf("%c",&i);
		if(i=='0')
		break;
		getchar(); 
	}
	return 0;
}
