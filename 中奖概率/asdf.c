#include <stdio.h>
#include <math.h>
double fun(double n2)
{
	int n = (int) n2;
	if(n==1||n==0) return 1;//如果参数是0或者1返回1
	return n2*fun(n2-1.0);//否则返回n和下次递归的积
}
//小心溢出，像指数，阶乘这种东西很容易溢出，千万小心，先要估计自己的计算范围才能写程序。
int main ()
{
	double day=0;
	double probability=0;
	double all = 0;
	double between = 0;

	//30 0.062
	//printf("%lf\n",fun(30) );
	printf("this programa only caculate probability which tring times less then 30 and\nprobability having less digits than 0.062\nmaybe it will work to other values not matching above standards, you can try\n"); 
	printf("input order is day and probability(no %c input such as 50%c)\n",'%','%');
	scanf("%lf",&day);
	scanf("%lf",&probability);
	double i=1.0 ;
	int day2=(int)day;
	int i2=0;
	for (;i2<day2 ; i++)
	{   
		i2= (int)i;
		between = fun(day)/fun(day-i)/fun(i)*pow(probability,i)*pow((1.0-probability),(day-i));
		printf("Probability of hitting %-2d out of %d times   %e\n", i2,day2,between);
		all= all + between;
		printf("Accumulation   %e\n",all);
		printf("\n");
	}
	return 0;
}