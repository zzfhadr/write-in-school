#include<stdio.h> //����ƽ���ֵ��������̫�� 
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
    char head[100]="  ����     ѧ��    ����  ��ѧ  Ӣ��    ƽ����  ";
    char stu[5][10],ipkg[5][10];
    float e[5],m[5],c[5],ad[3];
    FILE *fw;
    printf("�������������ѧ������Ϣ��");
    for(a=0;a<5;a++)
    {
        printf("������ѧ��������");
        gets(stu[a]);
        printf("������ѧ��ѧ�ţ�");
        gets(ipkg[a]);
        printf("�밴˳����������Ӣ�ɼ�");
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


















