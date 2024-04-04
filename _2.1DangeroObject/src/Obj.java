public class Obj {
    private  String name;
    boolean danger;
    Obj (String n,boolean d)
    {
        this.danger=d;
        name=n;

    }
    public  String getName()
    {
        return name;

    }

    public boolean isDanger()
    {
        return danger;
    }
}
