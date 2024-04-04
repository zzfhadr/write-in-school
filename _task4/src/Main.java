import java.util.Calendar;

public class Main {
    public static void main(String[] args) {
        Task4 cb= new Task4();
        cb.setYear(2022);
        cb.setMonth(6);
        String [] a= cb.getCalendar();
        char[] str="日一二三四五六".toCharArray();
        for(char c:str)
        {
            System.out.printf("%3c",c);

        }
        for(int i=0;i<a.length;i++)
        {
            if(i%7==0)
                System.out.println("");
            System.out.printf("%2s",a[i]);
            System.out.printf("  ");
        }
    }
}