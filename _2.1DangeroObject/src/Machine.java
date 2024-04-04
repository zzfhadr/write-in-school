public class Machine {

    public static  void check(Obj o) throws DangerException
    {
        if(o.isDanger())
            throw new DangerException(o.getName());
            else
                System.out.println("the "+o.getName()+" is Ok.");

    }
    public static void main(String[] args)
    {
        Obj[] objs={
                new Obj("cloth",false),new Obj("hat",false)
                ,new Obj("poison",true)
        };
        for(Obj o:objs)
        {
            try{
                check(o);

            }catch (DangerException e)
            {
                System.out.println(e.getMessage());
            }
        }
    }
}
