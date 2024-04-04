public class CellPhone
{
    private SimCard card1=new SimCard("");
    private SimCard card2=new SimCard("");
    private Battery battery=new Battery(0);
    CellPhone(SimCard c1,SimCard c2,Battery bt)
    {
        card1=c1;
        card2=c2;
        battery=bt;
    }
    CellPhone(SimCard c1,Battery bt)
    {
        card1=c1;
        battery=bt;
    }
    public void setCard1(SimCard c)
    {
        card1=c;
    }
    public void setCard2(SimCard c)
    {
        card2=c;
    }
    public String getCard1Number()
    {
        return card1.getNumber();
    }
    public String getCard2Number()
    {
        return card2.getNumber();
    }
    public void setBattery(Battery bt)
    {
        battery=bt;

    }
    public  int getBatteryCapacity()
    {
        return battery.getCapacity();
    }
}
