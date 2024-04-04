#include<stdio.h>
int datetodays(int year,int month ,int day)
{
	int di; 	
	di=0;
	switch (month-1)
	{
     case 12:
	 di=31;
	 case 11:
	 di+=30;
	 case 10:
	 di+=31;
	 case 9:
	 di+=30;
	 case 8:
	 di+=31;
	 case 7:
	 di+=31;
	 case 6:
	 di+=30;
	 case 5:
	 di+=31;
	 case 4:
	 di+=30;
	 case 3:
	 di+=31;
	 case 2:
	 {
 		if((year%4==0&&year%100!=0)||(year%400==0))
 		di+=29;
 		else
 		di+=28;
 	 }
	 case 1:
	 di+=31;  	
	}
	di+=day;
	return(di);
}
	int sui(int j,int b)
{
   if(b>0&&b<33)
   printf("%d日",b);
   if(b<0&&b>-32)
   {
   j--;
  return (j);
   }
   if(b>0)
   return (j);
}
int main()
{
  	int year,day,month,di,d,days,choice;
  	printf("如果日期转换成天数，输入1。如果指定年份和第几天求出日期，输入2:");
  	scanf("%d",&choice);
  	if(choice==1)
  	{
	  	printf("please enter year month day in turn");
	    scanf("%d%d%d",&year,&month,&day);
	    di=datetodays(year,month,day);
        printf("第%d天",di);	
	  }
    if(choice==2)
    { 
	month=1,d=0;
	printf("please enter year days in turn");
	scanf("%d%d",&year,&days);
	days-=31,month++;
	d=sui(month,days);
	if((year%4==0&&year%100!=0)||(year%400==0))
	days-=29,month++;
	else
	days-=28,month++;
	d=sui(month,days);
	days-=31,month++;
	d=sui(month,days);
	days-=30,month++;
	d=sui(month,days);
	days-=31,month++;
	d=sui(month,days);
	days-=30,month++;
	d=sui(month,days);
	days-=31,month++;
	d=sui(month,days);
	days-=31,month++;
	d=sui(month,days);
	days-=30,month++;
	d=sui(month,days);
	days-=31,month++;
	d=sui(month,days);
	days-=30,month++;
	d=sui(month,days);
	days-=31,month++;
	d=sui(month,days);
	printf("  %d月",d);
	}	
}