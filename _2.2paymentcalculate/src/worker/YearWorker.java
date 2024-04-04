package worker;

public class YearWorker extends Employee {
    public YearWorker(double bs,double bn)
    {
        super(bs,bn);
    }
    public double earning()
    {

        return  basic+bonus;
    }
}
