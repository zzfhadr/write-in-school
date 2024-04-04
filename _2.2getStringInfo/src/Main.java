import javax.swing.plaf.basic.BasicLabelUI;
import java.util.StringTokenizer;

public class Main {
    public String[] asldfjw(String astringah)
    {
        String[] abc= new String[] {"","","","",""};
        int j=0;
        int i;
        for( i =0 ;i<astringah.length();i++)
        {
           if( astringah.charAt(i)!='，')
           {

               abc[j]=abc[j]+astringah.charAt(i);
           }
           else
           {
               j++;
           }

        }

        return  abc;
    }
    public static void main(String[] args) {
       //姓名：张三，出生时间：1989.10.16，个人网站：www.zhang.com，身高：1.85m，体重：72000g。
        Main adsf=new Main();
        String [] abc=new String[5];
        abc=adsf.asldfjw("姓名：张三，出生时间：1989.10.16，个人网站：www.zhang.com，身高：1.85m，体重：72000g。");
        abc[1]=abc[1].substring(0,2)+"年月"+abc[1].substring(4,9)+"年"+abc[1].substring(10,12)+"月"+abc[1].substring(13,15)+"日";
        abc[2]="主页"+abc[2].substring(4);
        String str=abc[3].replaceAll("[^0-9.]","#");
        StringTokenizer tokens = new StringTokenizer(str,"#");
        String  shengdo= tokens.nextToken();
        Double sdhngd=Double.parseDouble(shengdo);
        sdhngd=sdhngd*100;
        abc[3]=abc[3].substring(0,3)+sdhngd+"cm";

         str=abc[4].replaceAll("[^0-9.]","#");
        StringTokenizer tokens2 = new StringTokenizer(str,"#");
        String  tjiz= tokens2.nextToken();
        Double tisjdf=Double.parseDouble(tjiz);
        tisjdf=tisjdf/1000;
        abc[4]=abc[4].substring(0,3)+tisjdf+"kg";
        System.out.println(abc[0]);
        System.out.println(abc[1]);
        System.out.println(abc[2]);
        System.out.println(abc[3]);
        System.out.println(abc[4]);
    }
}