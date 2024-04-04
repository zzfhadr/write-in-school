import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String str="烤鸭：89.9元，水饺：30.5元，青菜：11.9元，餐具：4.5元";
        String adf;
        Scanner sc=new Scanner(str);
        sc.useDelimiter("[^\\d.]+");
        double sum=0,nws;
        while(sc.hasNext())
        {
            adf=sc.next();
            nws=Double.parseDouble(adf);
            sum=sum+nws;

        }
        System.out.println("总价格为："+sum+"元");
    }
}