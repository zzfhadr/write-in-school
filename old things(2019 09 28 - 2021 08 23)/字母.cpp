struct WORD
{
	float m;
	char n;	
};

#include <stdio.h>
int uuu(WORD a[26])
{
	int c,d;
	WORD f;
	for(d=0;d<26;d++)
	{
	for(c=d+1;c<26;c++)
	if(a[d].m>a[c].m)
	{
		f=a[c];
		a[c]=a[d];
		a[d]=f;
	}
	//for(c=0;c<26;c++)
	//printf("%2d ",a[c]);
	//printf("\n");
	}
	return 0;
	
}
int main()
{
	WORD chart[26]={{8.19,'A'},{1.47,'B'},{3.83,'C'},{3.91,'D'},{12.25,'E'},{2.26,'F'},
	{1.71,'G'},{4.57,'H'},{7.10,'I'},{0.14,'J'},{0.41,'K'},{3.77,'L'},{3.34,'M'},
	{7.06,'N'},{7.26,'O'},{2.89,'P'},{0.09,'Q'},{6.85,'R'},{6.36,'S'},{9.41,'T'},
	{2.58,'U'},{1.09,'V'},{1.59,'W'},{0.21,'X'},{1.58,'Y'},{0.08,'Z'},};
	uuu(chart);
	int i;
	for(i=0;i<26;i++)
	{
		printf("%-12f %c\n",chart[i].m,chart[i].n);
	}
	return 0;	
}