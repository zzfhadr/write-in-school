import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner=new Scanner(System.in);
        String Firstdate =scanner.nextLine();
        String Seconddate= scanner.nextLine();
        String osdf;
        int i,day1=0,day2=0;
        Scanner sc=new Scanner(Firstdate);
        sc.useDelimiter("[^\\d]+");

        osdf=sc.next();
        i=Integer.parseInt(osdf);
        day1=i*365;
        osdf=sc.next();
        i=Integer.parseInt(osdf);
        day1=day1+i*30;
        osdf=sc.next();
        i=Integer.parseInt(osdf);
        day1=day1+i;

        Scanner sc2=new Scanner(Seconddate);
        sc2.useDelimiter("[^\\d]+");

        osdf=sc2.next();
        i=Integer.parseInt(osdf);
        day2=i*365;
        osdf=sc2.next();
        i=Integer.parseInt(osdf);
        day2=day2+i*30;
        osdf=sc2.next();
        i=Integer.parseInt(osdf);
        day2=day2+i;
        if(day1>day2)
        {
            i=day1-day2;
            System.out.println(Firstdate+"和"+Seconddate+"相差"+i+"天"+"，其中第一个日期较大。");
        }

        else if (day2>day1)
        {
            i=day2-day1;
            System.out.println(Firstdate+"和"+Seconddate+"相差"+i+"天"+"，其中第二个日期较大。");
        }
        else if (day2==day1)

        System.out.println(Firstdate+"和"+Seconddate+"相差0天"+"，两个日期一样大。");


    }
}