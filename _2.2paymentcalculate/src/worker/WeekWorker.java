package worker;

public class WeekWorker extends  Employee {
    double unit;
    public WeekWorker(double n,double bs)
    {

        super(bs,0);
    }
    public double earning()
    {
        double gongzi;
        gongzi=unit*basic;
        return  gongzi;
    }
}
