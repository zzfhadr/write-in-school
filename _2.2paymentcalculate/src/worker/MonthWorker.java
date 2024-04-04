package worker;

public class MonthWorker extends Employee {
    double unit=10.5;
    public MonthWorker(double bs,double bn)
    {
        super(bs,bn);
    }
    public double earning()
    {
        double gongzi;
        gongzi=unit*basic+10.0*bonus;
        return  gongzi;
    }
}
