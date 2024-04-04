#include<stdio.h> //三个平均分的输出好像不太好 
#include<stdlib.h>
float cal(float g[])
{
	float b=0.0;
	int a;
	for(a=0;a<5;a++)
	b=g[a]+b;	
	return(b/5.0);	
}
int main()
{
    int a;
    //double adven[5];
    char head[100]="  姓名     学号    语文  数学  英语    平均分  ";
    char stu[5][10],ipkg[5][10];
    float e[5],m[5],c[5],ad[3];
    FILE *fw;
    printf("请依次输入五个学生的信息：");
    for(a=0;a<5;a++)
    {
        printf("请输入学生姓名：");
        gets(stu[a]);
        printf("请输入学生学号：");
        gets(ipkg[a]);
        printf("请按顺序输入语数英成绩");
		scanf("%f%f%f",&c[a],&m[a],&e[a]);
		getchar();
    }
    fw=fopen("list.txt","w");
    fprintf(fw,"%s\n",head);
    printf("xfk js\n");
   /* for(a=0;a<5;a++)
    {
        adven[a]=(atof(c[a])+atof(m[a])+atof(e[a]))/3.0;
        sprintf(ad[a],"%f\n",adven[a]);
    }*/
    ad[0]=cal(c);
    ad[1]=cal(m);
    ad[2]=cal(e);    
    for(a=0;a<5;a++)
    {
    	fprintf(fw,"%5s%10s%6.2f%6.2f%6.2f",stu[a],ipkg[a],c[a],m[a],e[a]);
		if(a<3)
		fprintf(fw,"%10.2f",ad[a]);
		fprintf(fw,"\n");    			 	
	}
	fclose(fw);
    return 0;
}


















