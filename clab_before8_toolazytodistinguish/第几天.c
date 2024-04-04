#include <stdio.h>
int main()
{
	int year,day,month,di;
     for(;;)
	{
    printf("please enter year month day in turn");
	scanf("%d%d%d",&year,&month,&day);  //you can just keep this from 'for'
	if(month<1||month>12||day<1||day>31)
	continue;
	break;
	}
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
	printf("%d\n",di);
	return 0;

}
 