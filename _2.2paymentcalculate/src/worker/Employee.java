package worker;

public abstract class Employee {
    int unit=1;
    double basic;
    double bonus;
    public  Employee(double bs,double bn)
    {
        basic=bs;
        bonus=bn;

    }
    public  abstract double earning();
}
