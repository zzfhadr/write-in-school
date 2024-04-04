import worker.*;
public class Section {
    private Employee[] employees;
    public  Section(Employee[] maps)
    {
        employees=maps;
    }
    public double countSalaries()
    {
        double sum=0;
       for(int i=0;i< employees.length;i++)
       {
          sum=sum+ employees[i].earning();
       }
        return  sum;
    }
    public static void main(String[] agrs)
    {
        Employee[] mps={
            new YearWorker(50000d,32000d),new MonthWorker(4500d,3000d),
        new MonthWorker(4200d,2800d),new WeekWorker(40.5,1250d),
        new WeekWorker(40.5,1250d),new WeekWorker(40.5,1250d)
    };
        Section s=new Section(mps);
        System.out.println("6个员工的工资总和为："+s.countSalaries());

    }
}
