import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        System.out.println("请输入一个1至99999之间的数字");
        Scanner reader = new Scanner(System.in);
        int number = reader.nextInt();

        int d1,d2,d3,d4,d5;
        if(number>=1&&number<=99999) {
            d1=number%10;
            d2=(number%100)/10;
            d3=(number%1000)/100;
            d4=(number%10000)/1000;
            d5=(number%100000)/10000;

            if(d5!=0){
                if(d5==d1&&d2==d4){
                    System.out.println("该数是一个回文数");
                }else{
                    System.out.println("该数不是一个回文数");
                }
            }else if(d4!=0){
                if(d4==d1&&d2==d3){
                    System.out.println("该数是一个回文数");
                }else{
                    System.out.println("该数不是一个回文数");
                }
            }else if (d3!=0){
                if(d3==d1){
                    System.out.println("该数是一个回文数");
                }else{
                    System.out.println("该数不是一个回文数");
                }
            }else if (d2!=0){
                if(d2==d1){
                    System.out.println("该数是一个回文数");
                }else{
                    System.out.println("该数不是一个回文数");
                }
            }else  {
                System.out.println("该数是一个回文数");
            }
        }
        else{
            System.out.println("输入数字不合法！");
        }
    }
}