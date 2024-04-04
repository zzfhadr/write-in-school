import javax.swing.plaf.DimensionUIResource;
import java.util.Scanner;
import java.util.SplittableRandom;

public class Village {
    static  int waterAmount;
   private   String name;
    private int  peopeleNumber;
    public void setName(String snsd)
    {

        name =snsd;
    }
    public void setPeopeleNumber(int pewwhow)
    {

        peopeleNumber=pewwhow;
    }
    public  int getPeopeleNumber()
    {
        return peopeleNumber;
    }
    public  String getName()
    {
        return name;
    }
    Village(String name,int peopeleNumber)
    {
        this.name=name;
        this.peopeleNumber=peopeleNumber;
    }
    public void  setWaterAmount(int sdf23)
    {
       waterAmount=sdf23;

    }
    public  int getWaterAmount()
    {
        return waterAmount;
    }
    public void  drinkWater(int duskwater)
    {
        if(waterAmount-duskwater>0)
        {
            waterAmount=waterAmount-duskwater;
            System.out.println(name+"村当前使用"+duskwater +"量的井水");
        }
        else
            System.out.println("井水不足");
    }

}
