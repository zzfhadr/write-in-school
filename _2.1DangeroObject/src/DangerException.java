public class DangerException extends  Exception {

    private String msg;
    public  DangerException(String n)
    {
        msg="the "+n+" is danger.";
    }
    public String getMessage()
    {
        return msg;
    }
}
