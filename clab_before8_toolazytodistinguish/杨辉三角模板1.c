#include <stdio.h>

/* 
 * ����׳ˣ���������ܻ��롣ΪʲôҪ��float�������Ե�һ�ε�ʱ��
 * �����int�Ļ�����ô�ڴ�ӡ���������Ժ�ͻ����
 * ������Ϊ�׳˵����Ƚϴ������int�Ͳ������ˡ���ͬ
 */
float J(int i){
    int j;
    float k=1;
    for(j=1;j<=i;j++)
        k=k*j;
    return(k);
}
float C(int i,int j){  /*���������*/
    float k;
    k=J(j)/(J(i)*J(j-i));
    return(k);
}
int main(){
    int i=0,j,k,n;  /*��ӡ�������*/ 
    while(i<=0||i>16){
        printf("������Ҫ��ӡ��������");
        scanf("%d",&i);
    }
    printf("%d������������£�\n",i);

    for(j=0;j<i;j++){
        for(k=1;k<=(i-j);k++)
            printf("  ");
        for(n=0;n<=j;n++)
            printf("%4.0f",C(n,j));
        printf("\n");
    }
    printf("\n\n");
}